#include "holberton.h"

/**
 * pall - Function that prints the stack
 * @stack: stack structure
 * @line_number_ Number of instruction
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	int n = 0;

	if (*stack == NULL)
		return;

	temp = *stack;

	while (temp)
	{
		n = temp->n;
		printf("%d\n", n);
		temp = temp->next;
	}
}
