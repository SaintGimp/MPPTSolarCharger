#include <atmel_start.h>
#include <hal_gpio.h>
#include <stdio.h>
#include <cstring>

#include "console.h"
#include "console_io.h"
#include "systick.h"
#include "blinky.h"
#include "adc_single_shot.h"
#include "ina260.h"

static void calibrate_adc();
static void initialize_i2c();

Blinky builtin_led(LED_BUILTIN, 250);
adc::SingleShotAdc example_adc(0);
current_monitor::Ina260 ina260(&I2C_0, 0x40, I2C_M_SEVEN);

// *** Metro M0 pinout ***
// ADC pin: A0 (PA02)
// Serial RX: D0 (PA11)
// Serial TX: D1 (PA10)
// Built-in LED: D13 (PA17)
// PWM: D4 (PA08)
// CPU clock output: D2 (PA14)

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	calibrate_adc();
	initialize_i2c();
	ina260.Reset();

	// Disable automatic NVM write operations
	NVMCTRL->CTRLB.bit.MANW = 1;

	// Frequency of 186.662KHz
	// (CONF_CPU_FREQUENCY / 257 because the clock takes one extra cycle to reset)
	// If we want better than 8-bit resolution at the same frequency, need to move up to M4
	pwm_set_parameters(&PWM_0, 256, 128);
	pwm_enable(&PWM_0);	

	systick::Initialize();
	console::Initialize();
	example_adc.Initialize();

	while (true)
	{
		uint32_t current_milliseconds = systick::millis();

		console::Process();
		example_adc.Process();

		builtin_led.update(current_milliseconds);
	}
}

void calibrate_adc()
{
	// Why doesn't START do this automatically?
	hri_adc_calib_reg_t bias = (*((uint32_t*) ADC_FUSES_BIASCAL_ADDR) & ADC_FUSES_BIASCAL_Msk) >> ADC_FUSES_BIASCAL_Pos;
	hri_adc_write_CALIB_BIAS_CAL_bf(ADC, bias);
	// Bits 7:5
	hri_adc_calib_reg_t linearity1 = ((*((uint32_t*) ADC_FUSES_LINEARITY_1_ADDR) & ADC_FUSES_LINEARITY_1_Msk) >> ADC_FUSES_LINEARITY_1_Pos);
	// Bits 4:0
	hri_adc_calib_reg_t linearity0 = (*((uint32_t*) ADC_FUSES_LINEARITY_0_ADDR) & ADC_FUSES_LINEARITY_0_Msk) >> ADC_FUSES_LINEARITY_0_Pos;
	hri_adc_write_CALIB_LINEARITY_CAL_bf(ADC, linearity1 << 5 | linearity0);
}

void initialize_i2c()
{
	// Set baud rate here if different than default
	i2c_m_sync_enable(&I2C_0);
}

void SetBlinkRate(int32_t blink_rate)
{
	builtin_led.set_blink_rate(blink_rate);
}

void SetDutyCycle(int8_t duty_cycle)
{
	pwm_set_parameters(&PWM_0, 256, (pwm_period_t)(256 * (duty_cycle / 100.0)));
}

void StartAdcReading(adc::AdcCallback callback)
{
	example_adc.StartConversion(callback);
}

void PrintCurrentMonitorData()
{
	printf("INA260 data:\r\n");
	printf("Voltage: %f V\r\n", ina260.GetVoltageReading());
	printf("Current: %f A\r\n", ina260.GetCurrentReading());
	printf("Power: %f W\r\n", ina260.GetPowerReading());
	printf("Configuration: ");
	console::ConsoleIoSendInt(ina260.GetConfiguration(), 2);
	printf("\r\n");
}

void SetCurrentMonitorAveragingMode(uint8_t mode)
{
	ina260.SetAveragingMode(mode);
}

void SetCurrentMonitorVbusConversionTime(uint8_t value)
{
	ina260.SetVbusConversionTime(value);
}

void SetCurrentMonitorCurrentConversionTime(uint8_t value)
{
	ina260.SetCurrentConversionTime(value);
}

void TestCurrentMonitor(uint16_t delayBetweenSamples)
{
	uint16_t voltageReadings[10];
	memset(voltageReadings, 0, sizeof(voltageReadings));
	uint16_t currentReadings[10];
	memset(currentReadings, 0, sizeof(currentReadings));

	uint16_t baselineVoltage = ina260.GetRawVoltageReading();
	uint16_t baselineCurrent = ina260.GetRawCurrentReading();

	for (int x = 0; x < 10000; x++)
	{
		uint16_t rawVoltage = ina260.GetRawVoltageReading();
		voltageReadings[rawVoltage - baselineVoltage + 5]++;

		uint16_t rawCurrent = ina260.GetRawCurrentReading();
		currentReadings[rawCurrent - baselineCurrent + 5]++;
		
		delay_ms(delayBetweenSamples);
	}

	printf("Voltage distribution:\r\n");
	for (int x = 0; x < 10; x++)
	{
		printf("%d: %d\r\n", (baselineVoltage - 5 + x), voltageReadings[x]);
	}
	printf("Current distribution:\r\n");
	for (int x = 0; x < 10; x++)
	{
		printf("%d: %d\r\n", (baselineCurrent - 5 + x), currentReadings[x]);
	}
}

void HardFault_Handler(void)
{
	printf("FATAL: Crashed into hard fault handler!");

    while (true)
	{
    }
}