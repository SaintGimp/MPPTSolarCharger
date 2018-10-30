#ifndef BLINKY_H_INCLUDED
#define BLINKY_H_INCLUDED

#include <inttypes.h>

class Blinky
{
    public:
        Blinky(uint32_t gpio, int32_t blink_rate_in_ms);
        void update(int32_t current_milliseconds);
        void set_blink_rate(int32_t blink_rate_in_ms);

    private:
        uint32_t gpio;
        int32_t blink_rate_in_ms;
        int32_t previous_milliseconds = 0U;
};

#endif
