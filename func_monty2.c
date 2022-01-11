#include "monty.h"

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