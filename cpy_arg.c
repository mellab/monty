#include "monty.h"

/**
 * cpy_arg - function that copies argument of push in buffer
 * @buff: buffer to be copied the argument
 * @t: linked list of instructions
 * Return: 0 if it fails or other positive number otherwise
 */
int cpy_arg(list_t *t, char *buff)
{
	int i, j;

	for (i = 0; i < 10024; i++)
		buff[i] = 0;

	for (i = 5, j = 0; t->inst[i] != '\0' && t->inst[i] != ' '; i++, j++)
		buff[j] = t->inst[i];

	buff[j] = '\0';

	return (j);
}
