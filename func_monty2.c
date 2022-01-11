#include "monty.h"

/**
 * my_add - add the two last integer in a stack_t list
 * @stack: stack where the two integers are
 * @line_number: line of the command
 */
void my_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		error_add(line_number);
		return;
	}
	(*stack)->next->n += (*stack)->n;
	my_pop(stack, line_number);
}

/**
 * my_nop - doesn't do anything
 * @stack: stack
 * @line_number: line of the command
 */

void my_nop(stack_t **stack __attribute__((unused)),
unsigned int line_number __attribute__((unused)))
{
	;
}
