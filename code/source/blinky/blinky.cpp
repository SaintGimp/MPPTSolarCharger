#include <hal_gpio.h>

#include "blinky.h"

Blinky::Blinky(uint32_t gpio, int32_t blink_rate_in_ms)
{
    this->gpio = gpio;
    this->blink_rate_in_ms = blink_rate_in_ms;
}

void Blinky::update(int32_t current_milliseconds)
{
    if ((current_milliseconds - previous_milliseconds) >= blink_rate_in_ms)
    {
        gpio_toggle_pin_level(gpio);
        previous_milliseconds = current_milliseconds;
    }           
}

void Blinky::set_blink_rate(int32_t blink_rate_in_ms)
{
    this->blink_rate_in_ms = blink_rate_in_ms;
}

