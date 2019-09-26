#include "monty.h"

/**
 * get_file - a function for getting the monty ByteCode files
 * @str: String to be checked
 * Return: line counter. Otherwise if it fails, return the status EXIT_FAILURE
 */

int get_file(char *str)
{
	char *line_buf = NULL;
	char buff[1024];
	char *b = buff;
	size_t line_buf_size = 0;
	int line_counter = 0, i, j;
	ssize_t line_size = 0;
	FILE *fp = fopen(str, "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}

	line_size = getline(&line_buf, &line_buf_size, fp);

	for (i = 0; i < 1024; i++)
		buff[i] = 0;

	while (line_size >= 0)
	{
		for (i = 0, j = 0; line_buf[i] && line_buf[i] != '\n'; i++)
			if (line_buf[i] != ' ')
				j++;

		line_counter++;
		if (j > 0)
		{
			clean_string(b, line_buf);
			create_instruction(&list_opcode, buff, line_counter);
		}


		line_size = getline(&line_buf, &line_buf_size, fp);
	}

	free(line_buf);
	line_buf = NULL;
	fclose(fp);
	return (line_counter);
}
