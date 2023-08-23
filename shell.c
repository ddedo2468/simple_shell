#include "shell.h"

/**
  * run_shell - Runs the interactive shell
  * Return: void
  */
void run_shell(void)
{
	int interactive_mode = isatty(fileno(stdin));
	char input[MAX_INPUT_LENGTH], *args[MAX_ARG_COUNT];
	int exit_status = 0;

	while (1)
	{
		if (interactive_mode)
			print_prompt(interactive_mode);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
			{
			}
			else
			{
				perror("fgets");
				exit(EXIT_FAILURE);
			}
			break;
		}

		remove_newline(input);

		if (!strcmp(input, "exit"))
		{
			handle_exit_command(exit_status);
			break;
		}
		if (!strcmp(input, "env"))
		{
			handle_env_command();
			continue;
		}

		tokenize_input(input, args);
		execute_command(args[0], args, &exit_status);

	}
}
/**
 * main - Entry point for the shell program
 * Return: 0
 */
int main(void)
{
	run_shell();
	return (0);
}
