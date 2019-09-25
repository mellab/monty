#include "holberton.h"

int cmp_inst(char *str1, char *str2)
{
	int i = 0, n = 0;

	for (i = 0; str1[i] && str1[i] != ' ' && str1[i] != '\n'; i++)
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
