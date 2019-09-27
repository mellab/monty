#ifndef MONTY_H_
#define MONTY_H_

#define UN __attribute__((__unused__))

/* Standard Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

/* Structs and Lists */

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
 * @n: number of line
 * @inst: instruction of opcode and its function
 * @next: points to the next element of the linked list
 * Description: Single linked list of the struct instruction
 */
typedef struct list_s
{
	int n;
	char *inst;
	struct list_s *next;
} list_t;

extern list_t *list_opcode;

/* Prototype Functions */

int get_file(char *str);
void check_file(char *str);
list_t *create_instruction(list_t **head, char *str, int n, FILE *fp);
void (*ptr_opcode(list_t *head))(stack_t **stack, unsigned int line_number);
char *_strdup(char *str, FILE *fp);
int _strlen(char *str);
int clean_string(char *buff, char *str);
void free_list_opcode(list_t *head);
void *_calloc(unsigned int nmemb, unsigned int size);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void nothing(stack_t **stack, unsigned int line_number);
int cmp_inst(char *str1, char *str);
stack_t *add_nodeint(stack_t **head, const int n);
void free_all(list_t *list_opcode, stack_t *stack);
void free_list_stack(stack_t *head);
void swap(stack_t **stack, UN unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
int stack_len(stack_t *head);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(UN stack_t **stack, UN unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
int check_arg(char *buff);
int cpy_arg(list_t *t, char *buff);
void print_error_push(stack_t **stack, int line_number);
void _div(stack_t **stack, unsigned int line_number);
void _mul(stack_t **stack, unsigned int line_number);
void _mod(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void core_stack_queue(stack_t **stack, unsigned int line_number, int sq);
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, UN unsigned int line_number);
void rotl(stack_t **stack, UN unsigned int line_number);
void rotr(stack_t **stack, UN unsigned int line_number);

#endif /* MONTY_H_ */
