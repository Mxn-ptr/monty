#include "monty.h"

/**
 * split_cmd - split the command
 * @cmd: command to split
 *
 * Return: command splited or NULL if failed
 */

char *split_cmd(char *cmd)
{
	char *cmd_splited;

	cmd_splited = strtok(cmd, "\n ");
	if (cmd_splited == NULL)
		return (NULL);
	return (cmd_splited);
}

instruction_f check_cmd(char *str)
{
	int i = 0;

	instruction_t cmd[] = {
		{"push", my_push},
		{"pall", my_pall},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{NULL, NULL}
	};
	
	while (cmd[i].f != NULL && strcmp(cmd[i].opcode, str) != 0)
		i++;
	return (cmd[i].f);	
}

int get_cmd(FILE *fd_code, stack_t **stack)
{
	char *buffer = NULL, *line;
	unsigned int line_number = 1;
	size_t i;
	instruction_f check;
	int read;

	while ((read = getline(&buffer, &i, fd_code)) != -1)
	{
		line = split_cmd(buffer);
		if (line == NULL || line[0] == '#')
		{
			line_number++;
			continue;
		}
		check = check_cmd(line);
		if (check == NULL)
			return (error_op(line, line_number));
		
		check(stack, line_number);
		line_number++;
	}
	free(buffer);
	return (EXIT_SUCCESS);
}
