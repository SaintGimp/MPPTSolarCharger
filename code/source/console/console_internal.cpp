#include <stdint.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
#include <utility>

#include "console_io.h"
#include "console_commands.h"
#include "console_internal.h"

namespace console
{
    // Local functions
    static int32_t StringToNumber(const char *p, char **out_p, int base);

    void CommandCompleted()
    {
		ConsoleIoSend(kConsolePrompt);
    }

	// Find the start location of the nth parameter in the buffer where the command itself is parameter 0
	bool ParamFindN(const char * buffer, const uint8_t parameterNumber, uint32_t *startLocation)
	{
		uint32_t bufferIndex = 0;
		uint32_t parameterIndex = 0;

		while ((parameterNumber != parameterIndex) && (bufferIndex < kConsoleCommandMaxLength))
		{
			if (buffer[bufferIndex] == kParameterSeparator)
			{
				parameterIndex++;
			}
			bufferIndex++;
		}

		if  (bufferIndex == kConsoleCommandMaxLength)
		{
			return false;
		}

        *startLocation = bufferIndex;
		return true;
	}

	// Identify and obtain a parameter
	template <typename T>
    bool ReceiveParameter(const char * buffer, const uint8_t parameterNumber, T* parameterValue)
	{
		uint32_t startIndex = 0;

		if (!ParamFindN(buffer, parameterNumber, &startIndex))
		{
            return false;
        }

        *parameterValue = StringToNumber(buffer + startIndex, nullptr, 0);

		return true;
	}

    // In order to have the definition of a template function in a cpp file, we need
    // to explicitly instantiate the template types we expect to use.
    // TODO: not entirely sure this is the best way to do this.
    template bool ReceiveParameter<int8_t>(const char * buffer, const uint8_t parameterNumber, int8_t* parameterValue);
    template bool ReceiveParameter<uint8_t>(const char * buffer, const uint8_t parameterNumber, uint8_t* parameterValue);
    template bool ReceiveParameter<int16_t>(const char * buffer, const uint8_t parameterNumber, int16_t* parameterValue);
    template bool ReceiveParameter<uint16_t>(const char * buffer, const uint8_t parameterNumber, uint16_t* parameterValue);
    template bool ReceiveParameter<int32_t>(const char * buffer, const uint8_t parameterNumber, int32_t* parameterValue);
    template bool ReceiveParameter<uint32_t>(const char * buffer, const uint8_t parameterNumber, uint32_t* parameterValue);

	// Identify and obtain a parameter of type uint16
	bool ReceiveParamUint16(const char * buffer, const uint8_t parameterNumber, uint16_t* parameterValue)
	{
		uint32_t startIndex = 0;

		if (!ParamFindN(buffer, parameterNumber, &startIndex))
		{
            return false;
        }

        *parameterValue = StringToNumber(buffer + startIndex, nullptr, 0);

		return true;
	}

    static int32_t StringToNumber(const char *p, char **out_p, int base)
    {
        int32_t value = 0;
        bool is_neg = false;

        while (isspace(*p))
        {
            p++;
        }

        if (*p == '-')
        {
            is_neg = true;
            p++;
        }
        else if (*p == '+')
        {
            is_neg = false;
        }

        if (((base == 16) || (base == 0)) && ((*p == '0') && ((p[1] == 'x') || (p[1] == 'X'))))
        {
            p += 2;
            base = 16;
        }
        else if (((base == 8) || (base == 0)) && (*p == '0'))
        {
            base = 8;
        }
        else if (((base == 2) || (base == 0)) && ((*p == 'b') || (*p == 'B')))
        {
            p += 1;
            base = 2;
        }
        else if (base == 0)
        {
            base = 10;
        }

        while (true)
        {
            char c = *p;
            
            if ((c >= '0') && (c <= '9') && (c - '0' < base))
            {
                value = (value * base) + (c - '0');
            }
            else if ((c >= 'a') && (c <= 'z') && (c - 'a' + 10 < base))
            {
                value = (value * base) + (c - 'a' + 10);
            }
            else if ((c >= 'A') && (c <= 'Z') && (c - 'A' + 10 < base))
            {
                value = (value * base) + (c - 'A' + 10);
            }
            else
            {
                break;
            }

            p++;
        }

        if (is_neg)
        {
            value = -value;
        }

        if (out_p)
        {
            *out_p = (char*)p;
        }

        return value;
    }
}