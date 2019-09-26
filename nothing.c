#include "holberton.h"

/**
 * nothing - Function that frees if there is not coincidence
 * @stack: stack structure
 * @line_number: Number of instruction
 */
void nothing(stack_t **stack, unsigned int line_number)
{
	if (list_opcode != NULL)
		free_list_opcode(list_opcode);

	if (*stack != NULL)
		free_list_stack(*stack);

	exit(EXIT_FAILURE);
}
