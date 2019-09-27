#include "monty.h"

/**
 * free_all - Function that frees all the memory heap
 * @list: List of instructions
 * @stack: List of stack
 */
void free_all(list_t *list, stack_t *stack)
{
	if (list_opcode)
		free_list_opcode(list);
	if (stack)
		free_list_stack(stack);
}
