#include "holberton.h"

/**
 * cmp_inst - Function that compares instructions with the function pointers
 * @str1: String 1
 * @str2: String 2
 * Return: 0 on success and -1 otherwise
 */
int cmp_inst(char *str1, char *str2)
{
	int i = 0, n = 0;

	for (i = 0; str2[i]; i++)
	{
		if (str1[i] == str2[i])
			n = 0;
		else
		{
			n = str1[i] - str2[i];
			break;
		}
	}

	return (n);
}
