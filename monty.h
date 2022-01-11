#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes errors functions */
int error_usage(void);
int error_open(char *filename);
int error_op(char *opcode, unsigned int line_number);
int error_malloc(void);
int error_push(unsigned int line_number);

/* Prototypes for read command */
char *split_cmd(char *cmd);
typedef (*instruction_f)(stack_t **stack, unsigned int line_number);
instruction_f check_cmd(char *str);
int get_cmd(FILE *fd_code, stack_t **stack);

/* Prototypes monty's functions */
int my_push(stack_t **stack, unsigned int line_number);
int my_pall(stack_t **stack, unsigned int line_number);
int my_pint(stack_t **stack, unsigned int line_number);
int my_pop(stack_t **stack, unsigned int line_number);
int my_swap(stack_t **stack, unsigned int line_number);
int my_nop(stack_t **stack, unsigned int line_number);
int my_add(stack_t **stack, unsigned int line_number);


#endif /*MONTY_H*/
