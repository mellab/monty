#include "monty.h"

/**
 * create_instruction - Function that creates a node in the list of opcode
 * @head: Head of the opcode linked list
 * @str: String to be added in the linked list
 * Return: 0 on succes or -1 if it fails
 */
list_t *create_instruction(list_t **head, char *str)
{
	list_t *new = NULL;
	list_t *last = NULL;
	static int n = 1;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->inst = _strdup(str);
	new->next = NULL;

	n++;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	last = *head;

	while (last->next)
		last = last->next;

	last->next = new;

	return (*head);
}
