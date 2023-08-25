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
	int token_count;

	while (1)
	{
		if (interactive_mode)
			print_prompt(interactive_mode);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			if (feof(stdin))
				break;
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

		token_count = tokenize_input(input, args);
		if (token_count > 0)
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
