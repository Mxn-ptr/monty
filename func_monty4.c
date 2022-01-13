#include "monty.h"

/**
 * my_pstr - print string of stack
 * @stack: stack to print
 * @line_number: line to check
 *
 * Return: nothing
 */
void my_pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;
	int c;

	if (is_empty(stack) == 0)
	{
		_putchar('\n');
		return;
	}

	while (tmp != NULL)
	{
		c = tmp->n;
		if (c == 0)
			break;
		if(!isprint(c))
			break;
		_putchar(c);
		tmp = tmp->next;
	}
	printf("\n");
}

