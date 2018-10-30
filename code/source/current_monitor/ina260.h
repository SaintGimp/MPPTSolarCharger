#ifndef INA260_H
#define INA260_H

#include <stdint.h>

namespace current_monitor
{
    // Registers
    const int INA260_REGISTER_CONFIGURATION = 0x00;
    const int INA260_REGISTER_CURRENT = 0x01;
    const int INA260_REGISTER_VOLTAGE = 0x02;
    const int INA260_REGISTER_POWER = 0x03;
    const int INA260_REGISTER_MANUFACTURER_ID = 0xFE;

    // Average modes
    const int INA260_AVERAGE_MODE_POSITION = 9;
    const int INA260_AVERAGE_MODE_MASK = 0b111 << INA260_AVERAGE_MODE_POSITION;
    const int INA260_AVERAGE_MODE_1 = 0b000;
    const int INA260_AVERAGE_MODE_4 = 0b001;
    const int INA260_AVERAGE_MODE_16 = 0b010;
    const int INA260_AVERAGE_MODE_64 = 0b011;
    const int INA260_AVERAGE_MODE_128 = 0b100;
    const int INA260_AVERAGE_MODE_256 = 0b101;
    const int INA260_AVERAGE_MODE_512 = 0b110;
    const int INA260_AVERAGE_MODE_1024 = 0b111;

    // VBUS conversion times
    const int INA260_VBUS_CONVERSION_POSITION = 6;
    const int INA260_VBUS_CONVERSION_MASK = 0b111 << INA260_VBUS_CONVERSION_POSITION;
    const int INA260_VBUS_CONVERSION_140_US = 0b000;
    const int INA260_VBUS_CONVERSION_204_US = 0b001;
    const int INA260_VBUS_CONVERSION_332_US = 0b010;
    const int INA260_VBUS_CONVERSION_588_US = 0b011;
    const int INA260_VBUS_CONVERSION_1_1_MS = 0b100;
    const int INA260_VBUS_CONVERSION_2_116_MS = 0b101;
    const int INA260_VBUS_CONVERSION_4_156_MS = 0b110;
    const int INA260_VBUS_CONVERSION_8_244_MS = 0b111;

    // Current conversion times
    const int INA260_CURRENT_CONVERSION_POSITION = 3;
    const int INA260_CURRENT_CONVERSION_MASK = 0b111 << INA260_CURRENT_CONVERSION_POSITION;
    const int INA260_CURRENT_CONVERSION_140_US = 0b000;
    const int INA260_CURRENT_CONVERSION_204_US = 0b001;
    const int INA260_CURRENT_CONVERSION_332_US = 0b010;
    const int INA260_CURRENT_CONVERSION_588_US = 0b011;
    const int INA260_CURRENT_CONVERSION_1_1_MS = 0b100;
    const int INA260_CURRENT_CONVERSION_2_116_MS = 0b101;
    const int INA260_CURRENT_CONVERSION_4_156_MS = 0b110;
    const int INA260_CURRENT_CONVERSION_8_244_MS = 0b111;

    class Ina260
    {
        public:
        Ina260(struct i2c_m_sync_desc* i2c, int16_t address, int32_t address_length);
        void Reset();
        uint16_t GetConfiguration();
        void SetAveragingMode(uint8_t mode);
        void SetVbusConversionTime(uint8_t value);
        void SetCurrentConversionTime(uint8_t value);
        uint16_t GetRawCurrentReading();
        float GetCurrentReading();
        uint16_t GetRawVoltageReading();
        float GetVoltageReading();
        uint16_t GetRawPowerReading();
        float GetPowerReading();
        uint16_t GetManufacturerId();
        
        private:
        float GetDataRegisterValue(uint8_t registerAddress, float lsbValue);
        uint16_t GetRegisterValue(uint8_t registerAddress);
        void SetRegisterValue(uint8_t registerAddress, uint16_t value);
        void SetSlaveAddress();
        uint16_t ConvertToUint16(uint8_t* buffer);
        int16_t ConvertToSigned(uint16_t twosComplement);

        struct i2c_m_sync_desc* i2c;
        int16_t address;
        int32_t address_length;
    };
}

#endif // INA260_H
