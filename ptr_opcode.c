#include "holberton.h"

/**
 * ptr_opcode - Pointer function of struct array
 * @head: Head of the list
 * Return: pointer to an array of structures
 */

void (*ptr_opcode(list_t *head))(stack_t **stack, unsigned int line_number)
{
	int i, n;

	instruction_t arr_ptr[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; arr_ptr[i].f; i++)
	{
		n = cmp_inst(head->inst, arr_ptr[i].opcode);
		if (n == 0)
			return (arr_ptr[i].f);
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", head->n, head->inst);

	return (nothing);
}
