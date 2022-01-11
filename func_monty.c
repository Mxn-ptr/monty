#include "monty.h"

int my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int num = 0;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (error_malloc());
	arg = strtok(NULL, "\n ");
	

}
int my_pall(stack_t **stack, unsigned int line_number)
{

}
int my_pint(stack_t **stack, unsigned int line_number)
{

}
int my_pop(stack_t **stack, unsigned int line_number)
{

}
int my_swap(stack_t **stack, unsigned int line_number)
{

}
