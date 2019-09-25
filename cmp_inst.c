#include "holberton.h"

int cmp_inst(char *str1, char *str2)
{
	int i, n;

	for (i = 0; str1[i] && (str2[i] != ' ' || str1[i] != '\t'); i++)
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
