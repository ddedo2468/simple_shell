#include "shell.h"

/**
  * handle_exit_command - Handles the exit command, terminating the shell
  * @exit_status: to specify wheather success or failure
  * Return: void
  */
void handle_exit_command(int exit_status)
{
	if (exit_status == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		exit(2);
	}
}
