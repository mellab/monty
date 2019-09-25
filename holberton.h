#ifndef HOLBERTON_H_
#define HOLBERTON_H_

#define <stdio.h>
#define <stdlib.h>
#define <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct list_s - linked list of struct instruction
 * @inst: instruction of opcode and its function
 * @next: points to the next element of the linked list
 * Description: Single linked list of the struct instruction
 */
typedef struct list_s
{
	struct instruction_s *inst;
	struct list_s *next;
} list_t;

extern list_t *list;

int get_file(char *str);
void print_error(int n);
int create_instruction(char *str);
void (*ptr_opcode)(stack_t **stack, unsigned int line_number);
void free_all(stack_t *stack);

#endif
