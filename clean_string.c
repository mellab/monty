#include "holberton.h"

/**
 * clean_string - Function that cleans a string
 * @buff: buffer to store string
 * @str: String to be cleaned
 * Return: The length of string
 */
int clean_string(char *buff, char *str)
{
	int i, j, k = 0;

	for (i = 0, j = 0; str[i] || str[i] != '\n'; i++)
	{
		for (; str[i] != ' ' && str[i] != '\t'; i++, j++)
		{
			buff[j] = str[i];
			k = 1;
		}
		if (k == 1)
			break;
	}

	buff[j] = ' ';
	j++;

	for (; str[i] || str[i] != '\n'; i++)
	{
		for (; str[i] != ' ' && str[i] != '\t'; i++, j++)
		{
			buff[j] = str[i];
			k = 0;
		}
		if (k == 0)
			break;
	}

	buff[j] = '\0';

	return (j);
}
