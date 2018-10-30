#include <atmel_start.h>
#include "adc_single_shot.h"

// The conversion time and the maximum allowable input imedance is determined
// by the ADC clock and the sample length set in ASF.
// https://github.com/arduino/ArduinoCore-samd/issues/327
// https://github.com/adafruit/ArduinoCore-samd/issues/51
// http://www.avdweb.nl/arduino/libraries/fast-10-bit-adc.html

namespace adc
{
    void driver_callback(const struct adc_async_descriptor *const descr, const uint8_t channel)
    {
        // Because we're trying to do this in an instance class, it's not easy to directly
        // interact with this callback so we'll poll instead.  We do have to regiser a
        // callback anyway, though, in order to get the driver to start up the interupt.
    }

    SingleShotAdc::SingleShotAdc(uint8_t channel)
    {
        this->channel = channel;
    }

    void SingleShotAdc::Initialize()
    {
        adc_async_register_callback(&ADC_0, channel, ADC_ASYNC_CONVERT_CB, driver_callback);
        adc_async_enable_channel(&ADC_0, channel);
    }

    void SingleShotAdc::Process()
    {
        uint8_t buffer[2];

        int32_t bytes_received = adc_async_read_channel(&ADC_0, channel, buffer, 2);

        if (bytes_received > 0 && client_callback != nullptr)
        {
            uint16_t value = buffer[0];
            value |= buffer[1] << 8;

            client_callback(value);
        }
    }

    void SingleShotAdc::StartConversion(AdcCallback callback)
    {
        client_callback = callback;
    	adc_async_start_conversion(&ADC_0);
    }
}