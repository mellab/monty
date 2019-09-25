#include "holberton.h"

list_t *list;

/**
 * main - Main entry point for Stacks and Queues
 * @argc: Argument count for the matrix
 * @argv: Argument vector for the matrix
 * Return: 0 on success or other number if it fails
 */
int main(int argc, char **argv)
{
	int line_number;
	stack_t *stack = NULL;

	if (argv != 2)
	{
		print_error(0);
		exit(98);
	}

	line_number = get_file(argv[1]);
	(*ptr_opcode)(&stack, line_number);
	free_all(stack);
	return (0);
}
