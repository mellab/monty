#include "monty.h"

void print_error_push(stack_t **stack, int line_number);

/**
 * push - Function that pushes nodes in the stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i = 0, j = 0, k = 0;
	char buff[1024];
	list_t *t = NULL;

	if (list_opcode != NULL)
		t = list_opcode;

	for (; t->next; t = t->next)
		if (t->n == (int) line_number)
			break;

	for (i = 0; i < 1024; i++)
		buff[i] = 0;
	i = 5;
	for (; j < 1024 && t->inst[i] != '\n' && t->inst[i] != EOF; i++, j++)
	{
		if (t->inst[i] == '\0' || t->inst[i] == ' ' || t->inst[i] == '\t')
			break;
		if (t->inst[i] >= '0' && t->inst[i] <= '9')
			k = 1;
		if (k == 1 && (t->inst[i] < '0' || t->inst[i] > '9'))
		{
			k = 2;
			break;
		}
		buff[j] = t->inst[i];
	}
	if (k == 2)
		print_error_push(stack, line_number);
	if (t->inst[5] < '0' || t->inst[5] > '9')
	{
		k = 0;
		if (t->inst[5] == '-' || t->inst[5] == '+')
		{
			k = 1;
			if (t->inst[6] < '0' || t->inst[6] > '9')
				k = 0;
		}
	}

	if (k == 0)
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
