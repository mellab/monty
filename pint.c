#include "holberton.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: stack structure
 * @line_number: Number of instructions
 */

void pint(stack_t **stack, unsigned int line_number)
{


	if (*stack == NULL)
	{
		printf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_list_stack(*stack);
		exit(EXIT_FAILURE);
	}
	print("%d\n", (*stack)->n);
}
