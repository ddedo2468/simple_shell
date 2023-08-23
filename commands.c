 #include "shell.h"

/**
  * execute_command - Executes a command with the provided arguments
  * by creating a child process
  * @command: The command to be executed
  * @args: pointer to array of argument strings for the command
  * @error: pointer to exit status of child process
  * Return: void
  */
void execute_command(char *command, char **args, int *error)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		*error = EXIT_FAILURE;
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (strcmp(command, "ls") == 0)
		{
			if (execve("/bin/ls", args, environ) == -1)
			{
				fprintf(stderr, "./hsh: %s\n", strerror(errno));
				*error = EXIT_FAILURE;
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (execve(command, args, environ) == -1)
			{
				fprintf(stderr, "./hsh: %s: %s\n", command, strerror(errno));
				*error = EXIT_FAILURE;
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		waitpid(child_pid, error, 0);
	}
}
