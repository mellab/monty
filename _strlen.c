#include "monty.h"

/**
 * _strlen - Function that calculates a length of string
 * @str: String to be checked
 * Return: The length of string or -1 if it fails
 */

int _strlen(char *str)
{
	int i;

	if (str == NULL)
		return (-1);

	for (i = 0; str[i]; i++)
		;

	return (i);
}
