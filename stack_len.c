#include "monty.h"

/**
 * stack_len - Function that calculates the lengt of stack
 * @head: Head of the stack
 * Return: the length
 */
int stack_len(stack_t *head)
{
	int i = 0;

	for (; head; head = head->next, i++)
		;

	return (i);
}
