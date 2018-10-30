// Adapted from https://github.com/eleciawhite/reusable

// This is where you add commands:
//		1. Implement the function, using ReceiveParameter() to get the parameters from the buffer.
//		2. Add the command to command_table
//		    {"ver", &CommandVer, "Get the version string"}

#include <array>
#include "console_internal.h"
#include "console_commands.h"
#include "console_io.h"
#include "version.h"

// Interface functions to affect the rest of the application
// TODO: should be in a header
void SetBlinkRate(int32_t blink_rate);
void SetDutyCycle(int8_t duty_cycle);
void StartAdcReading(void (*)(uint16_t adc_value));
void PrintCurrentMonitorData();
void SetCurrentMonitorAveragingMode(uint8_t mode);
void SetCurrentMonitorVbusConversionTime(uint8_t value);
void SetCurrentMonitorCurrentConversionTime(uint8_t value);
void TestCurrentMonitor(uint16_t delayBetweenSamples);

namespace console
{	
	extern const CommandTable command_table;

	static bool CommandComment(const char /*buffer*/[])
	{
		// do nothing
		return true;
	}

	static bool CommandHelp(const char /*buffer*/[])
	{
		for (auto& command : command_table)
		{
			ConsoleIoSend("%s : %s\r\n", command.name, command.help);
		}

		CommandCompleted();
		return true;
	}

	static bool CommandSetBlinkRate(const char buffer[])
	{
		int16_t blink_rate;

		if (!ReceiveParameter(buffer, 1, &blink_rate))
		{
			return false;
		}

		SetBlinkRate(blink_rate);

		ConsoleIoSend("Blink rate set to %d ms.\r\n", blink_rate);

		CommandCompleted();
		return true;
	}

	static bool CommandParameterExample(const char buffer[])
	{
		uint8_t parameter;

		if (!ReceiveParameter(buffer, 1, &parameter))
		{
			return false;
		}

		ConsoleIoSend("Parameter is %d.\r\n", parameter);

		CommandCompleted();
		return true;
	}

	static bool CommandVer(const char /*buffer*/[])
	{
		ConsoleIoSend("%s\r\n", VERSION_STRING);

		CommandCompleted();
		return true;
	}

	static bool CommandSetDutyCycle(const char buffer[])
	{
		uint8_t parameter;

		if (!ReceiveParameter(buffer, 1, &parameter))
		{
			return false;
		}

		SetDutyCycle(parameter);

		ConsoleIoSend("Duty cycle set to %d.\r\n", parameter);

		CommandCompleted();
		return true;
	}

	static bool CommandGetAdcReading(const char buffer[])
	{
		StartAdcReading([](const uint16_t adc_value)
		{
			ConsoleIoSend("ADC reading is %d.\r\n", adc_value);
	
			CommandCompleted();
		});

		return true;
	}

	static bool CommandGetCurrentMonitorData(const char buffer[])
	{
		PrintCurrentMonitorData();

		CommandCompleted();
		return true;
	}

	static bool CommandSetCurrentMonitorAveragingMode(const char buffer[])
	{
		uint8_t parameter;

		if (!ReceiveParameter(buffer, 1, &parameter))
		{
			return false;
		}

		SetCurrentMonitorAveragingMode(parameter);

		ConsoleIoSend("Current monitor averaging mode set to %d.\r\n", parameter);

		CommandCompleted();
		return true;
	}

	static bool CommandSetCurrentMonitorVbusConversionTime(const char buffer[])
	{
		uint8_t parameter;

		if (!ReceiveParameter(buffer, 1, &parameter))
		{
			return false;
		}

		SetCurrentMonitorVbusConversionTime(parameter);

		ConsoleIoSend("Current monitor VBUS conversion time set to %d.\r\n", parameter);

		CommandCompleted();
		return true;
	}

	static bool CommandSetCurrentMonitorCurrentConversionTime(const char buffer[])
	{
		uint8_t parameter;

		if (!ReceiveParameter(buffer, 1, &parameter))
		{
			return false;
		}

		SetCurrentMonitorCurrentConversionTime(parameter);

		ConsoleIoSend("Current monitor current conversion time set to %d.\r\n", parameter);

		CommandCompleted();
		return true;
	}

	static bool CommandTestCurrentMonitor(const char buffer[])
	{
		uint8_t parameter;

		if (!ReceiveParameter(buffer, 1, &parameter))
		{
			return false;
		}

		TestCurrentMonitor(parameter);

		CommandCompleted();
		return true;
	}

	// When you add new commands here, you also need to change the size
	// of the std::array in the header file
	const CommandTable command_table =
	{
		CommandTableEntry {";", &CommandComment, "Comment! You do need a space after the semicolon."},
		CommandTableEntry {"help", &CommandHelp, "Lists the commands available"},
		CommandTableEntry {"ver", &CommandVer, "Get the version string"},
		CommandTableEntry {"param", &CommandParameterExample, "Demonstrates parameters by echoing them: param 0xAB12"},
		CommandTableEntry {"set-blink-rate", &CommandSetBlinkRate, "Sets the LED blink rate in ms: set-blink-rate 500"},
		CommandTableEntry {"set-duty-cycle", &CommandSetDutyCycle, "Sets the duty cycle of the PWM output: set-duty-cycle <percentage>"},
		CommandTableEntry {"get-adc-reading", &CommandGetAdcReading, "Gets the present ADC reading"},
		CommandTableEntry {"get-current-monitor-data", &CommandGetCurrentMonitorData, "Gets current monitor data"},
		CommandTableEntry {"set-current-monitor-averaging-mode", &CommandSetCurrentMonitorAveragingMode, "Sets the current monitor averaging mode: set-current-monitor-averaging-mode <value>"},
		CommandTableEntry {"set-current-monitor-vbus-conversion-time", &CommandSetCurrentMonitorVbusConversionTime, "Sets the current monitor VBUS conversion time: set-current-monitor-vbus-conversion-time <value>"},
		CommandTableEntry {"set-current-monitor-current-conversion-time", &CommandSetCurrentMonitorCurrentConversionTime, "Sets the current monitor current conversion time: set-current-monitor-current-conversion-time <value>"},
		CommandTableEntry {"test-current-monitor", &CommandTestCurrentMonitor, "Test the current monitor: test-current-monitor <delayBetweenSamples>"}
	};

	CommandTable GetCommandTable()
	{
		return command_table;
	}
}