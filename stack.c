#include "monty.h"

int init(stack_t **stack)
{
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
		return (error_malloc());
}
