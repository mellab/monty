#include "monty.h"

/**
 * free_list_opcode - Function that frees the opcode linked list
 * @head: Head of the linked list
 */
void free_list_opcode(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->inst);
		free(temp);
	}
}
