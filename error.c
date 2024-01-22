#include "monty.h"

/**
 * errors - print the error mess assign to error
 * @errors_code: the error code below
 * 1: user does not give files or give multi file
 * 2: file can not read or open
 * 3: file contain valid instruction
 * 4: program not able to alloc memory
 * 5: instruction push is not int
 */
void errors(int errors_code, ...)
{
	va_list ag;
	char *ptr;
	int ln_num;

	va_start(ag, errors_code);
	if (errors_code == 1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (errors_code == 2)
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char *));
	else if (errors_code == 3)
	{
		ln_num = va_arg(ag, int);
		ptr = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", ln_num, ptr);
	}
	else if (errors_code == 4)
		fprintf(stderr, "Error: malloc failed\n");
	else if (errors_code == 5)
		fprintf(stderr, "l%d:usage: push integer\n", va_arg(ag, int));
	free_nd();
	exit(EXIT_FAILURE);
}

/**
 * moreoferrors - to hand the error
 * @errors_code: the error code below
 * 6: empty for pint
 * 7: stack is empty for pop
 * 8: stack is too short
 * 9: division by zero
 */
void moreoferrors(int errors_code, ...)
{
	va_list ag;
	char *ptr;
	int ln_num;

	va_start(ag, errors_code);
	if (errors_code == 6)
		fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
	else if (errors_code == 7)
		fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
	else if (errors_code == 8)
	{
		ln_num = va_arg(ag, unsigned int);
		ptr = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too shrt\n", ln_num, ptr);
	}
	else if (errors_code == 9)
		fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
	free_nd();
	exit(EXIT_FAILURE);
}

/**
 * string_of_errors - handle more error about string
 * @errors_code: the error codes
 * 10: num inside a node is out of ASCII
 * 11: stack is empty
 */
void string_of_errors(int errors_code, ...)
{
	va_list ag;
	int ln_num;

	va_start(ag, errors_code);
	ln_num = va_arg(ag, int);
	if (errors_code == 10)
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_num);
	else if (errors_code == 11)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_num);
	free_nd();
	exit(EXIT_FAILURE);
}

/**
 * rotr - rotate the last node of the stack to the top
 * @stack: pointer to pointer pointing top node of the stack
 * @ln: integer represent the line number of the opcode
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	temp->prev->next = NULL;
	temp->next = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}

