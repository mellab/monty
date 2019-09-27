#include "monty.h"

/**
 * pchar - Function that prints character at the top
 * @stack: stack structure
 * @line_number: Number of instructions
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		if (list_opcode)
			free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 && (*stack)->n > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		if (*stack)
			free_list_stack(*stack);
		if (list_opcode)
			free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}
