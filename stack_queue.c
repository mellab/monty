#include "monty.h"

/**
 * core_stack_queue - Function that manages stack and queue
 * @stack: stack structure
 * @line_number: Number of instructions
 * @sq: switch of stack and queue
 */
void core_stack_queue(stack_t **stack, unsigned int line_number, int sq)
{
	static int turn;
	int i, j;
	char buff[10024];
	char *b = buff;
	list_t *t = NULL;

	if (sq != 0)
	{
		turn = sq;
		return;
	}

	t = list_opcode;

	for (; t->next; t = t->next)
		if (t->n == (int) line_number)
			break;

	i = cpy_arg(t, b);

	j = check_arg(b);

	if (i == 0 || j == 0)
		print_error_push(stack, line_number);

	if (turn == 1)
		add_nodeint(stack, atoi(buff));
	else if (turn == 2)
		add_dnodeint_end(stack, atoi(buff));
	else
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
	if (*stack)
		free_list_stack(*stack);
	if (list_opcode)
		free_list_opcode(list_opcode);
	exit(EXIT_FAILURE);
}
