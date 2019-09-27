#include "monty.h"

/**
 * ptr_opcode - Pointer function of struct array
 * @head: Head of the list
 * Return: pointer to an array of structures
 */

void (*ptr_opcode(list_t *head))(stack_t **stack, unsigned int line_number)
{
	int i, n;
	char buff[10024];
	list_t *h = head;

	instruction_t arr_ptr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"queue", queue},
		{"stack", stack},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	for (i = 0; arr_ptr[i].f; i++)
	{
		n = cmp_inst(head->inst, arr_ptr[i].opcode);
		if (n == 0)
			return (arr_ptr[i].f);
	}
	for (i = 0; i < 10024; i++)
		buff[i] = 0;
	for (i = 0; h->inst[i] != '\n' && h->inst[i] && h->inst[i] != ' '; i++)
		buff[i] = h->inst[i];
	buff[i] = '\0';
	fprintf(stderr, "L%d: unknown instruction %s\n", head->n, buff);
	return (nothing);
}
