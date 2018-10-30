#include <peripheral_clk_config.h>
#include <sam.h>

#include "systick.h"

namespace systick
{
    volatile uint32_t elapsed_milliseconds = 0;

    void Initialize()
    {
        SysTick_Config(CONF_CPU_FREQUENCY / 1000);
    }

    uint32_t millis()
    {
        return elapsed_milliseconds;
    }

    void delay_ms(uint32_t milliseconds_to_delay)
    {
        uint32_t current_milliseconds = elapsed_milliseconds;
        while ((elapsed_milliseconds - current_milliseconds) < milliseconds_to_delay)
        {
        }
    }
}

void SysTick_Handler(void)
{
    systick::elapsed_milliseconds++;
}
