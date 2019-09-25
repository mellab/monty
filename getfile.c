#include "holberton.h"

/**
 * get_file - a function for getting the monty ByteCode files
 *
 * Return: line counter. Otherwise if it fails, return the status EXIT_FAILURE
 */

#define stdin "example.m"

int get_file(char *str)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_counter = 0;
	ssize_t line_size;
	FILE *fp = fopen(stdin, "r");

	if (!fp)
	{
		fprintf(stderr, "Error opening file '%s'\n", stdin);
		return (EXIT_FAILURE);
	}

	line_size = getline(&line_buf, &line_buf_size, fp);

	while (line_size >= 0)
	{
		create_instruction(line_buf);
		line_counter++;

		printf("line[%06d]: chars=06zd, buf size=%06zu, contents: %s",
		       line_counter, line_size, line_buf_size, line_buf);

		line_size = getline(&line_buf, &line_buf_size, fp);

		free(line_buf);
		line_buf = NULL;

		fclose(fp);

		return (line_counter);
	}

}
