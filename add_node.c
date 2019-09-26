#include "holberton.h"

/**
 * add_nodeint - insert a node at the head of the stack
 * @head: address to double linked list
 * @n: node to add
 * Return: address to the new node, otherwise return NULL
 */

stack_t *add_nodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list_opcode(list_opcode);
		if (head != NULL)
			free_list_stack(*head);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head)
		(*head)->prev = new;

	*head = new;
	return (new);
}
