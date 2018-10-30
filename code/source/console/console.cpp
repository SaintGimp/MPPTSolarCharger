// Adapted from https://github.com/eleciawhite/reusable

// Console is the generic interface to the command line.
// These functions should not need signficant modification, only
// to be called from the normal loop. Note that adding commands should
// be done in console commands.

#include <cstring>
#include <array>
#include <algorithm>

#include "console.h"
#include "console_internal.h"
#include "console_io.h"
#include "console_commands.h"

namespace console
{
	char receive_buffer[kConsoleCommandMaxLength];
	int32_t characters_received_so_far;

	// local functions
	static void HandleBackspaceCharacters(char* buffer, int32_t* numberOfCharacters);
	static int32_t CommandEndline(const char receive_buffer[], const int32_t filled_length);
	static bool CommandMatch(CommandTableEntry command, const char *buffer);
	static uint32_t ResetBuffer(char receive_buffer[], const int32_t filled_length, int32_t used_so_far);

	// Initialize the console interface and all it depends on
	void Initialize()
	{
		ConsoleIoInit();
		ConsoleIoSend("Welcome to the Consolinator, your gateway to testing code and hardware.");	
		ConsoleIoSend(kStringEndline);
		ConsoleIoSend(kConsolePrompt);
		characters_received_so_far = 0u;

		for (int i = 0 ; i < kConsoleCommandMaxLength ; i++)
		{
			receive_buffer[i] = kNullCharacter;
		}
	}

	// Looks for new inputs, checks for endline, then runs the matching command.
	// Call ConsoleProcess from a loop, it will handle commands as they become available
	void Process()
	{
		int32_t received;
		ConsoleIoReceive((uint8_t*)&(receive_buffer[characters_received_so_far]), ( kConsoleCommandMaxLength - characters_received_so_far ), &received);
		if (received > 0)
		{
			characters_received_so_far += received;
			HandleBackspaceCharacters(receive_buffer, &characters_received_so_far);
			int32_t command_end_of_line = CommandEndline(receive_buffer, characters_received_so_far);
			if (command_end_of_line >= 0)  // have complete string, find command
			{
				auto command_table = GetCommandTable();
				auto iterator = std::find_if(command_table.begin(), command_table.end(), [](const CommandTableEntry& command)
				{
					return CommandMatch(command, receive_buffer);
				});
				if (iterator != std::end(command_table))
				{
					auto& command = *iterator;

					if (!command.execute(receive_buffer))
					{
						ConsoleIoSend("Error: ");
						ConsoleIoSend(receive_buffer);

						ConsoleIoSend("Help: ");
						ConsoleIoSend(command.help);
						ConsoleIoSend(kStringEndline);

						ConsoleIoSend(kConsolePrompt);
					}
				}
				else if (command_end_of_line > 0)
				{
					ConsoleIoSend("Command not found.");
					ConsoleIoSend(kStringEndline);

					ConsoleIoSend(kConsolePrompt);
				}
				else
				{
					// The user just hit enter with no command
					ConsoleIoSend(kConsolePrompt);
				}

				characters_received_so_far = ResetBuffer(receive_buffer, characters_received_so_far, command_end_of_line);
				// If the command starts successfully, the prompt will be printed when it indicates ultimate completion.
			}
		}
	}

	// Look to see if the data in the buffer matches the command name given that
	// the strings are different lengths and we have parameter separators
	static bool CommandMatch(CommandTableEntry command, const char *buffer)
	{
		int length_of_name = strlen(command.name);

		// TODO: assumes that name length < buffer length, which should be true but isn't enforced
		for (int i = 0; i < length_of_name; i++)
		{
			if (command.name[i] != buffer[i])
			{
				return false;
			}
		}

		if (buffer[length_of_name] != ' '
			&& buffer[length_of_name] != kCarriageReturnCharacter
			&& buffer[length_of_name] != kLinefeedCharacter)
		{
			return false;
		}

		return true;
	}

	// In an ideal world, this would just zero out the buffer. However, thre are times when the
	// buffer may have data beyond what was used in the last command.
	// We don't want to lose that data so we move it to the start of the command buffer and then zero
	// the rest.
	static uint32_t ResetBuffer(char receive_buffer[], const int32_t filled_length, int32_t used_so_far)
	{
		int32_t i = 0;

		while (used_so_far < filled_length)
		{
			receive_buffer[i] = receive_buffer[used_so_far]; // move the end to the start
			i++;
			used_so_far++;
		}
		for (/* nothing */ ; i < kConsoleCommandMaxLength ; i++)
		{
			receive_buffer[i] =  kNullCharacter;
		}
		return (filled_length - used_so_far);
	}

	// Check to see where in the buffer stream the endline is; that is the end of the command and parameters
	static int32_t CommandEndline(const char receive_buffer[], const  int32_t filled_length)
	{
		int32_t i = 0;

		while ((receive_buffer[i] != kCarriageReturnCharacter)  && (receive_buffer[i] != kLinefeedCharacter)
				&& ( i < filled_length ) )
		{
			i++;
		}
		
		if (i < filled_length)
		{
			return i;
		}

		return -1;
	}

	static void HandleBackspaceCharacters(char* buffer, int32_t* numberOfCharacters)
	{
		for (int32_t i = 0; i < *numberOfCharacters; i++)
		{
			if (buffer[i] == 0x08 || buffer[i] == 0x7F)
			{
				for (int32_t j = i + 1; j < *numberOfCharacters; j++)
				{
					buffer[j - 2] = buffer[j];
				}
				*numberOfCharacters = *numberOfCharacters > 1 ? *numberOfCharacters - 2 : 0;
				buffer[*numberOfCharacters] = kNullCharacter;
			}
		}
	}
}


