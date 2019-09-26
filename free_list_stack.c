#include "monty.h"

/**
 * free_list_stack - Function that frees memory of the stack
 * @head: Head of the stack
 */
void free_list_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
