// Adapted from https://github.com/eleciawhite/reusable

// Console IO is a wrapper between the actual in and output and the console code
// In an embedded system, this might interface to a UART driver.

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <stdarg.h>
#include <atmel_start.h>
#include "console_io.h"

namespace console
{
    // Local functions
    static char* itoa(int value, char* buffer, int base);

	static void rx_cb_DEBUG_IO(const struct usart_async_descriptor *const io_descr)
	{
		// We get this callback for every character but we'll just wait and
		// get characters out of the circular buffer during the main app loop
		// so we don't tie up the interrupt.
	}

	bool ConsoleIoInit(void)
	{
		usart_async_register_callback(&DEBUG_IO, USART_ASYNC_RXC_CB, rx_cb_DEBUG_IO);
		usart_async_enable(&DEBUG_IO);

		// Prevent buffering of printf so everything gets sent immediately
		setbuf(stdout, nullptr);
		setvbuf(stdin, nullptr, _IONBF, 0);
		setvbuf(stdout, nullptr, _IONBF, 0);
		setvbuf(stderr, nullptr, _IONBF, 0);
		
		return true;
	}

	void EchoCharactersBackToSender(uint8_t *buffer, const int32_t number_of_characters)
	{
		for (int i = 0; i < number_of_characters; i++)
		{
			char ch = buffer[i];

			if (ch == 127)
			{
				// Handle backspace.  \b moves the cursor left but doesn't actually change
				// the screen buffer in the terminal so we output a space to overwrite the
				// character then backspace again to get the cursor in the correct spot.
				// Note that handling removal of chars from the buffer is done later.
				printf("\b \b");
			}
			else
			{
				printf("%c", ch);
				if (ch == '\r')
				{
					// User pressed ENTER, echo a newline as well.
					printf("\n");
				}
			}
		}
	}

	bool ConsoleIoReceive(uint8_t *buffer, const int32_t bufferLength, int32_t *readLength)
	{
		struct io_descriptor *io;
		usart_async_get_io_descriptor(&DEBUG_IO, &io);

		int32_t number_of_characters = io_read(io, buffer, bufferLength);
		
		EchoCharactersBackToSender(buffer, number_of_characters);

		*readLength = number_of_characters;

		return true;
	}

	bool ConsoleIoSend(const char *format, ...)
	{
		va_list args;
		va_start (args, format);
		vprintf (format, args);
		va_end (args);
		
		return true;
	}

	bool ConsoleIoSendInt(int32_t number, int radix)
	{
		// We could use printf for most purposes but it doesn't
		// do base-2 output, so we roll our own.

		const int kMaxInt32StringLength = 16;
    	char out[kMaxInt32StringLength];
		memset(out, 0, sizeof(out));

		itoa(number, out, radix);
		return ConsoleIoSend("%s", out);
	}

	bool ConsoleIoSendFloat(float number)
	{
		printf("%f", number);
		return true;
	}

	extern "C"
	{
		// These replace the stdio hooks with our own implementations
		int __attribute__((weak)) _read(int file, char *ptr, int len);
		int _write(int file, char* outgoing, int len);
	}

	int __attribute__((weak)) _read(int file, char *ptr, int len)
	{
		if (file != 0)
		{
			return -1;
		}

		struct io_descriptor *io;
		usart_async_get_io_descriptor(&DEBUG_IO, &io);
		int32_t number_of_characters = io_read(io, (uint8_t*)ptr, len);

		if (number_of_characters < 0)
		{
			return -1;
		}

		return number_of_characters;
	}

	int _write(int file, char* outgoing, int len)
	{
		while (usart_async_get_status(&DEBUG_IO, NULL) == ERR_BUSY)
		{
		}
		
		struct io_descriptor *io;
		usart_async_get_io_descriptor(&DEBUG_IO, &io);
		io_write(io, (const uint8_t*)outgoing, len);	

		while (usart_async_get_status(&DEBUG_IO, NULL) == ERR_BUSY)
		{
		}

		return len;
	}

    static inline void Swap(char *x, char *y)
    {
        char t = *x;
        *x = *y;
        *y = t;
    }

    static char* Reverse(char *buffer, int i, int j)
    {
        while (i < j)
        {
            Swap(&buffer[i++], &buffer[j--]);
        }

        return buffer;
    }

    // From http://www.techiedelight.com/implement-itoa-function-in-c/
    static char* itoa(int value, char* buffer, int base)
    {
        // invalid input
        if (base < 2 || base > 32)
        {
            return buffer;
        }

        // consider absolute value of number
        int n = abs(value);

        int i = 0;
        while (n)
        {
            int r = n % base;

            if (r >= 10)
            {
                buffer[i++] = 65 + (r - 10);
            }
            else
            {
                buffer[i++] = 48 + r;
            }

            n = n / base;
        }

        // if number is 0
        if (i == 0)
        {
            buffer[i++] = '0';
        }

        // If base is 10 and value is negative, the resulting string 
        // is preceded with a minus sign (-)
        // With any other base, value is always considered unsigned
        if (value < 0 && base == 10)
        {
            buffer[i++] = '-';
        }

        // null terminate string
        buffer[i] = '\0';

        // reverse the string and return it
        return Reverse(buffer, 0, i - 1);
    }    
}