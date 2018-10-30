// Adapted from https://github.com/eleciawhite/reusable

#ifndef CONSOLE_COMMANDS_H
#define CONSOLE_COMMANDS_H

#include <array>

namespace console
{
	// Command function signature
	using CommandFunction = bool(*)(const char buffer[]);

	struct CommandTableEntry
	{
		const char* name;
		CommandFunction execute;
		const char*  help;
	};

	using CommandTable = std::array<CommandTableEntry, 12>;

	CommandTable GetCommandTable();
}

#endif // CONSOLE_COMMANDS_H

