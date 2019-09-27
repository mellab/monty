#include "monty.h"

/**
 * check_file - Function that checks if file has monty extension
 * @str: String to be checked
 */
void check_file(char *str)
{
	int i;

	i = _strlen(str);

	if (str[i - 1] != 'm')
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		if (list_opcode)
			free_list_opcode(list_opcode);
		exit(EXIT_FAILURE);
	}
}
