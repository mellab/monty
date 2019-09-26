#include "holberton.h"

/**
 * push - Function that pushes nodes in the stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i= 0, j = 0, k = 0;
	list_t *temp = NULL;

	if (list_opcode != NULL)
	        temp = list_opcode;

	for (; temp->next; temp = temp->next)
		if (temp->n == line_number)
			break;

	if (temp->inst[5] < '0' || temp->inst[6] > '9')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (*stack != NULL)
			free_list_stack(*stack);
	        free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	for (i = 5, k; temp->inst[i] >= '0' && temp->inst[i] <= '9'; i++, k *= 10)
	{
		j *= k;
		j += temp->inst[i] - 48;
	}

	add_nodeint(stack, j);
}
