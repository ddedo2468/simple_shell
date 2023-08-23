#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 16

/*libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

/*functions declaration*/
extern char **environ;
void execute_command(char *command, char **args, int *error);
void remove_newline(char *str);
int tokenize_input(char *input, char **tokens);
void print_prompt(int interactive_mode);
void handle_exit_command(int exit_status);
void handle_env_command(void);
void run_shell(void);

#endif
