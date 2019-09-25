#include "holberton.h"

/**
 * ptr_opcode - Pointer function of struct array
 */
void (*ptr_opcode(void))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t arr_ptr[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; arr_ptr[i].f; i++)
	{
		if (cmp_inst(list_opcode->inst->opcode, arr_ptr[i].opcode) == 0)
		        return (arr_ptr[i].f);
	}

	return (nothing);
}
