#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
void call_fun(op_func, char *, char *, int, int);
/** handling errors in error .c*/
void errors(int errors_code, ...);
void moreoferrors(int errors_code, ...);
void string_of_errors(int error_code, ...);
void rotr(stack_t**, unsigned int);

/*Stack operations in stack_oper.c*/
stack_t *create_nd(int);
void free_nd(void);
void printstack(stack_t **, unsigned int);
void at_stack(stack_t **, unsigned int);
void at_queue(stack_t **, unsigned int);

/*file operations in file_oper.c*/
void op_file(char *);
void rd_file(FILE *);
int parse_ln(char *, int, int);
int len_chars(FILE *);
void find_fun(char *, char *, int, int);

/* math operation in math_node.c */
void add_nd(stack_t **, unsigned int);
void sub_nd(stack_t **, unsigned int);
void div_nd(stack_t **, unsigned int);
void mul_nd(stack_t **, unsigned int);
void mod_nd(stack_t **, unsigned int);

/* swap print po nop  stact_fun1.c */
void printop(stack_t **, unsigned int);
void poptop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nd(stack_t **, unsigned int);

/*String operations in stack_str.c*/
void printchar(stack_t **, unsigned int);
void printstr(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void call_fun(op_func, char *, char *, int, int);
#endif
