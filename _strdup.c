#include "holberton.h"

/**
 * _strdup - Function that returns a pointer to a newly allocated memory
 * @str: String to be allocated
 * Return: Return a string allocated or NULL if it fails
 */

char *_strdup(char *str)
{
	int i;
	char *new;

	if (str == NULL)
		return (NULL);

	i = _strlen(str);

	new = _calloc(i + 1, sizeof(char));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < str[i]; i++)
		new[i] = str[i];

	new[i] = '\0';

	return (new);
}
