#ifndef SYSTICK_INCLUDED
#define SYSTICK_INCLUDED

namespace systick
{
    void Initialize();
    uint32_t millis();
    void delay_ms();
}

#endif