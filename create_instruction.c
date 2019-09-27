#include "monty.h"

/**
 * create_instruction - Function that creates a node in the list of opcode
 * @head: Head of the opcode linked list
 * @str: String to be added in the linked list
 * @n: number of line
 * @fp: open file
 * Return: 0 on succes or -1 if it fails
 */
list_t *create_instruction(list_t **head, char *str, int n, FILE *fp)
{
	list_t *new = NULL;
	list_t *last = NULL;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		if (list_opcode)
			free_list_opcode(list_opcode);
		fclose(fp);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->inst = _strdup(str, fp);
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
