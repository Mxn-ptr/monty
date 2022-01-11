#include "monty.h"

/**
 * main - main of the monty interpreter
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */

int main(int argc, char **argv)
{
	stack_t *stack;
	FILE *fd_code = NULL;
	int status = EXIT_SUCCESS;

	if (argc != 2)
		return (error_usage());
	fd_code = fopen(argv[1], "r");
	if (fd_code == NULL)
		return (error_open(argv[1]));
	status = get_cmd(fd_code, &stack);
	fclose (fd_code);
	return (status);
}
