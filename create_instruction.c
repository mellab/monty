#include "holberton.h"

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

	new = calloc(1, sizeof(list_t));
	if (new == NULL)
	{
		print_error(1);
		exit(98);
	}

	new->inst = calloc(1, sizeof(instruction_t));
	if (new->inst == NULL)
	{
		print_error(1);
		exit(98);
	}
	new->inst->opcode = _strdup(str);
	new->next = NULL;

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
