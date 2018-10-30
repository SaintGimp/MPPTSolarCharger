// Adapted from https://github.com/eleciawhite/reusable

// Console IO is a wrapper between the actual in and output and the console code

#ifndef CONSOLE_IO_H
#define CONSOLE_IO_H

#include <stdint.h>

namespace console
{
    bool ConsoleIoInit(void);

    bool ConsoleIoReceive(uint8_t *buffer, const int32_t bufferLength, int32_t *readLength);
    bool ConsoleIoSend(const char *format, ...); // format must be null terminated
    bool ConsoleIoSendInt(int32_t number, int radix = 10);
    bool ConsoleIoSendFloat(float number);
}

#endif // CONSOLE_IO_H
