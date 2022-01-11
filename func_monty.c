#include "monty.h"

void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int num = 0;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_malloc();
	
	arg = strtok(NULL, "\n ");
	if (isnumber(arg) == 1 && arg != NULL)
	{
		num = atoi(arg);
		add_dnodeint(stack, num);
	}
	else
		error_push(line_number);
	return;
}
void my_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return;
}

