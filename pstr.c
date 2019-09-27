#include "monty.h"

/**
 * pstr - Function that prints string of the stack
 * @stack: stack structure
 * @line_number: number of instruction
 */
void pstr(stack_t **stack, UN unsigned int line_number)
{
	stack_t *temp = NULL;

	if (*stack == NULL)
	{
		putchar(10);
		return;
	}

	temp = *stack;

	while (temp)
	{
		if ((temp->n < 0 && temp->n > 126) || temp->n == 0)
		{
			putchar(10);
			return;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	putchar(10);
}
