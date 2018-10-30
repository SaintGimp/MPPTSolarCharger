#ifndef CONSOLE_INTERNAL_H
#define CONSOLE_INTERNAL_H

namespace console
{
	const int kConsoleCommandMaxLength = 256;
	const char kParameterSeparator = ' ';
	const char* const kStringEndline = "\r\n";
	const char kNullCharacter = '\0';
	const char kCarriageReturnCharacter = '\r';
	const char kLinefeedCharacter = '\n';
   	const char* const kConsolePrompt = "> ";

	void CommandCompleted();
	bool ParamFindN(const char * buffer, const uint8_t parameterNumber, uint32_t *startLocation);
	template <typename T>
    bool ReceiveParameter(const char * buffer, const uint8_t parameterNumber, T* parameterValue);
}

#endif // CONSOLE_H