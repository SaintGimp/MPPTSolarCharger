#include <stdio.h>
#include <atmel_start.h>
#include "ina260.h"

// INA260 datasheet:
// http://www.ti.com/lit/ds/symlink/ina260.pdf

namespace current_monitor
{
    Ina260::Ina260(struct i2c_m_sync_desc* i2c, int16_t address, int32_t address_length)
    {
        this->i2c = i2c;
        this->address = address;
        this->address_length = address_length;
    }

    void Ina260::Reset()
    {
        SetRegisterValue(INA260_REGISTER_CONFIGURATION, 0xFFFF);
    }

    uint16_t Ina260::GetConfiguration()
    {
        return GetRegisterValue(INA260_REGISTER_CONFIGURATION);
    }

    void Ina260::SetAveragingMode(uint8_t mode)
    {
        uint16_t configuration = GetRegisterValue(INA260_REGISTER_CONFIGURATION);
        configuration &= ~INA260_AVERAGE_MODE_MASK;
        configuration |= mode << INA260_AVERAGE_MODE_POSITION;
        SetRegisterValue(INA260_REGISTER_CONFIGURATION, configuration);
    }

    void Ina260::SetVbusConversionTime(uint8_t value)
    {
        uint16_t configuration = GetRegisterValue(INA260_REGISTER_CONFIGURATION);
        configuration &= ~INA260_VBUS_CONVERSION_MASK;
        configuration |= value << INA260_VBUS_CONVERSION_POSITION;
        SetRegisterValue(INA260_REGISTER_CONFIGURATION, configuration);
    }

    void Ina260::SetCurrentConversionTime(uint8_t value)
    {
        uint16_t configuration = GetRegisterValue(INA260_REGISTER_CONFIGURATION);
        configuration &= ~INA260_CURRENT_CONVERSION_MASK;
        configuration |= value << INA260_CURRENT_CONVERSION_POSITION;
        SetRegisterValue(INA260_REGISTER_CONFIGURATION, configuration);
    }

    uint16_t Ina260::GetRawVoltageReading()
    {
        return GetRegisterValue(INA260_REGISTER_VOLTAGE);
    }

    float Ina260::GetVoltageReading()
    {
        return ConvertToSigned(GetRawVoltageReading()) * 0.00125;
    }

    uint16_t Ina260::GetRawCurrentReading()
    {
        return GetRegisterValue(INA260_REGISTER_CURRENT);
    }

    float Ina260::GetCurrentReading()
    {
        return ConvertToSigned(GetRawCurrentReading()) * 0.00125;
    }

    uint16_t Ina260::GetRawPowerReading()
    {
        return GetRegisterValue(INA260_REGISTER_POWER);
    }

    float Ina260::GetPowerReading()
    {
        return GetRawPowerReading() * 0.010;
    }

    uint16_t Ina260::GetManufacturerId()
    {
        return GetRegisterValue(INA260_REGISTER_MANUFACTURER_ID);
    }

    uint16_t Ina260::GetRegisterValue(uint8_t registerAddress)
    {
        SetSlaveAddress();
        
        uint8_t buffer[2];
        int32_t result = i2c_m_sync_cmd_read(this->i2c, registerAddress, buffer, sizeof(buffer));
        if (result != 0)
        {
            printf("Failed to read from INA260 device, error code %ld\r\n", result);
        }

        return ConvertToUint16(buffer);
    }

    void Ina260::SetRegisterValue(uint8_t registerAddress, uint16_t value)
    {
        SetSlaveAddress();

        // i2c_m_sync_cmd_write doesn't work here, apparenty because
        // it does a restart after the address byte which messes up
        // the INA260.

        uint8_t buffer[3];
        buffer[0] = 0;
        buffer[1] = (value >> 8) & 0xFF;
        buffer[2] = value & 0xFF;

       	struct io_descriptor *I2C_0_io;
        i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
        io_write(I2C_0_io, buffer, sizeof(buffer));

        // uint8_t buffer[2];
        // buffer[0] = (value >> 8) & 0xFF;
        // buffer[1] = value & 0xFF;
        // int32_t result = i2c_m_sync_cmd_write(this->i2c, registerAddress, buffer, sizeof(buffer));
        // if (result != 0)
        // {
        //     printf("Failed to read from INA260 device, error code %ld\r\n", result);
        // }
    }

    void Ina260::SetSlaveAddress()
    {
        i2c_m_sync_set_slaveaddr(this->i2c, this->address, this->address_length);
    }

    uint16_t Ina260::ConvertToUint16(uint8_t* buffer)
    {
        return buffer[0] << 8 | buffer[1];
    }

    int16_t Ina260::ConvertToSigned(uint16_t twosComplement)
    {
        if (twosComplement < 0x8000)
        {
            return twosComplement;
        }
        else
        {
            return ~twosComplement -1;
        }
    }
}
