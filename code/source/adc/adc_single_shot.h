#ifndef ADC_SINGLE_SHOT_H
#define ADC_SINGLE_SHOT_H

#include <stdint.h>

namespace adc
{
    using AdcCallback = void(*)(uint16_t adc_reading);

    class SingleShotAdc
    {
        public:
        SingleShotAdc(uint8_t channel);
        void Initialize();
        void Process();
        void StartConversion(AdcCallback callback);

        private:
        uint8_t channel;
        AdcCallback client_callback;

        void DriverCallback(const struct adc_async_descriptor *const descr, const uint8_t channel);
    };
}

#endif // ADC_SINGLE_SHOT_H
