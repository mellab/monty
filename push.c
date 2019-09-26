#include "monty.h"

/**
 * push - Function that pushes nodes in the stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i, j;
	char buff[1024];
	char *b = buff;
	list_t *t = NULL;

	t = list_opcode;

	for (; t->next; t = t->next)
		if (t->n == (int) line_number)
			break;

	i = cpy_arg(t, b);

	j = check_arg(b);

	if (i == 0 || j == 0)
		print_error_push(stack, line_number);

	add_nodeint(stack, atoi(buff));
}


/**
 * print_error_push - function that prints error
 * @stack: stack structure
 * @line_number: Number of instruction
 */
void print_error_push(stack_t **stack, int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	if (*stack != NULL)
		free_list_stack(*stack);
	free_list_opcode(list_opcode);
	exit(EXIT_FAILURE);
}
