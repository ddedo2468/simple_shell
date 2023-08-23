#include "shell.h"
/**
  * remove_newline - Removes a trailing newline character from a string
  * @str: The string from which to remove the newline
  * Return: void
  */
void remove_newline(char *str)
{

	size_t length = strlen(str);

	if (length > 0 && str[length - 1] == '\n')
	{
		str[length - 1] = '\0';
	}
}

/**
  * tokenize_input - Parsing input string and split it into tokens
  * @input: The input string to be tokenized
  * @tokens: An array of pointers to store the tokens
  * Return: The number of tokens
  */
int tokenize_input(char *input, char **tokens)
{
	int token_count = 0;
	char *token = strtok(input, " ");

	while (token != NULL && token_count < MAX_ARG_COUNT - 1)
	{
		tokens[token_count] = token;
		token = strtok(NULL, " ");
		token_count++;
	}
	tokens[token_count] = NULL;

	return (token_count);
}

/**
  * print_prompt - Prints the shell prompt line
  * @interactive_mode: check if interative or not
  * Return: void
  */
void print_prompt(int interactive_mode)
{
	if (interactive_mode)
	{
		fprintf(stdout, "#Shell$ ");
		fflush(stdout);
	}
}

/**
  * string_compare - Comparison function for qsort
  * @i: 1st string
  * @j: 2nd string
  * Return: Negative if i < j, positive if i > j, 0 if equal
  */
int string_compare(const void *i, const void *j)
{
	return (strcmp(*(const char **)i, *(const char **)j));
}


/**
  * handle_env_command - Handles the environment command,
  * printing environment variables
  * Return: void
  */
void handle_env_command(void)
{
	int i, env_count;
	char **env_copy;

	env_count = 0;

	while (environ[env_count] != NULL)
	{
		env_count++;
	}
	env_copy = malloc((env_count + 1) * sizeof(char *));
	if (env_copy == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}


	for (i = 0 ; i < env_count ; i++)
	{
		env_copy[i] = environ[i];
	}
	env_copy[env_count] = NULL;

	qsort(env_copy, env_count, sizeof(char *), string_compare);

	for (i = 0 ; i < env_count ; i++)
	{
		printf("%s\n", env_copy[i]);
	}

	free(env_copy);
}
