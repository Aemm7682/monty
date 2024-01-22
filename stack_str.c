#include "monty.h"

/**
 * printchar - print ascii value
 * @stack: ptr to ptr pointing to the top node of the stack
 * @ln_num: represent the line number
 * Return: void
 */
void printchar(stack_t **stack, unsigned int ln_num)
{
	int number;

	if (stack == NULL || *stack == NULL)
		string_of_errors(11, ln_num);
	number = (*stack)->n;
	if (number < 0 || number > 127)
		string_of_errors(10, ln_num);
	printf("%c\n", number);
}

/**
 * printstr - print string
 * @stack: ptr to ptr pointing to the top node of the stack
 * @ln_num: represent the line number
 * Return: void
 */
void printstr(stack_t **stack, __attribute__((unused))unsigned int ln_num)
{
	int number;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	temp = *stack;
	while (temp != NULL)
	{
		number = temp->n;
		if (number <= 0 || number > 127)
			break;
		printf("%c", number);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - rotate the first node of the stack to the bottom
 * @stack: ptr to ptr pointing to the top node of the stack
 * @ln_num: represent the line number
 * Return: void
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * call_fun - call the required functions
 * @fun: ptr to function about call
 * @ptr: str present numeric number
 * @value: str present numeric value
 * @ln_num: line num in the instruction
 * @format: format specifer if 0 enter to stack
 * if 1 enter in queue
 */
void call_fun(op_func fun, char *ptr, char *value, int ln_num, int format)
{
	stack_t *nd;
	int flag;
	int i;

	flag = 1;
	if (strcmp(ptr, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			errors(5, ln_num);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				errors(5, ln_num);
		}
		nd = create_nd(atoi(value) * flag);
		if (format == 0)
			fun(&nd, ln_num);
		if (format == 1)
			at_queue(&nd, ln_num);
	}
	else
		fun(&head, ln_num);
}

