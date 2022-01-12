#include "monty.h"

/**
 * my_pstr - print string of stack
 * @line_number: line to check
 *
 * Return: nothing
 */
void my_pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	int i;

	if (is_empty(stack) == 0)
	{
		_putchar('\n');
		return;
	}

	else if (((*stack)->n <= 0) || ((*stack)->n > 127))
		return;

	for (i = 0; (*stack)->next != NULL; i++)
		_putchar((*stack)->n);

}

