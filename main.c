#include "holberton.h"

list_t *list_opcode = NULL;

/**
 * main - Main entry point for Stacks and Queues
 * @argc: Argument count for the matrix
 * @argv: Argument vector for the matrix
 * Return: 0 on success or other number if it fails
 */
int main(int argc, char **argv)
{
	int line_number = 0;
	stack_t *stack = NULL;
	list_t *temp;

	if (argc != 2)
	{
		print_error(0);
		exit(98);
	}

	line_number = get_file(argv[1]);

	temp = list_opcode;
	for (; temp; temp = temp->next)
		(*ptr_opcode(temp))(&stack, line_number);

	free_list_opcode(list_opcode);
	return (0);
}
