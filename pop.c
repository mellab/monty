#include "monty.h"

/**
 * pop - Function that remove the head of stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n;

	n = stack_len(*stack);
	if (n <= 0)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		if (list_opcode != NULL)
			free_list_opcode(list_opcode);
		if (*stack != NULL)
			free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
	temp = NULL;
}
