# simple_shell

simple_shell is a simple UNIX-like shell developed as part of an ALX collaboration project.
It is designed to read and execute user commands, providing basic shell functionalities.

## Features

- Interactive shell prompt.
- Execution of commands using child processes.
- Built-in commands handling (`exit`, `env`).
- Non-interactive mode support.
- Basic error handling.

## Getting Started

Follow these steps to get started with simple_shell:

1. Clone the repository:

   git clone https://github.com/SayedH-Dev/simple_shell

2. Compile the source code:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Run the shell: ./hsh

## Usage

- Enter commands and press Enter to execute them.
- Use the "exit" command to exit the shell.
- Use the "env" command to display environment variables.

## How It Works

CustomShell reads user commands, tokenizes them, and executes them using child processes.
It supports basic shell operations and provides a simple interface for users to interact with the system.

## Acknowledgments

This project was developed by the ALX collaboration team and inspired by the concepts of operating systems and C programming.

