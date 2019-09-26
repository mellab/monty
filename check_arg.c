#include "monty.h"

/**
 * check_arg - Function that checks if is a valid argument
 * @buff: buffer to be checked
 * Return: 0 if it fails or a positive number otherwise
 */
int check_arg(char *buff)
{
	int i;

	if (buff[0] == '-' || buff[0] == '+')
	{
		if (buff[1] < '0' || buff[1] > '9')
			return (0);
	}
	else if (buff[0] < '0' || buff[0] > '9')
		return (0);

	for (i = 1; buff[i] && buff[i] != ' '; i++)
		if (buff[i] < '0' || buff[i] > '9')
			return (0);

	return (1);
}
