#include "monty.h"

/**
 * is_empty - chack if stack is empty
 * @st: stack to check
 *
 * Return: empty stack
 */
int is_empty(stack_t **stack)
{
	if ((*stack)== NULL)
		return (0);
	return (1);
}

/**
 * pint - print last put element
 * @stack: stack to check
 *
 * Return: nothing
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	if (is_empty(stack) == 0)
	{
		error_pint(line_number);
		return;
	}
	printf("%d\n", (*stack)->n);
}

