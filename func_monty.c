#include "monty.h"

/**
 * my_push - push an integer in a stack_t list
 * @stack: stack where the number is push
 * @line_number: line of the command
 */
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
	}
	else
		error_push(line_number);
	add_dnodeint(stack, num);
	free(new);
}

/**
 * my_pall - prints a stack_t list
 * @stack: stack to print
 * @line_number: line of the command
 */

void my_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * my_pop - remove a node in a stack_t list
 * @stack: stack where the node is
 * @line_number: line of the command
 */

void my_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		error_pop(line_number);
		return;
	}
	(*stack) = (*stack)->next;
	free(tmp);
}

/**
 * my_swap - swap the two last integer in a stack_t list
 * @stack: stack where the two integers are
 * @line_number: line of the command
 */

void my_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL)
	{
		error_swap(line_number);
		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
