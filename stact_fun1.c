#include "monty.h"

/**
 * printop - print the top of the node
 * @stack: ptr to ptr pointing to top node of stack
 * @ln_num: line of opcode
 * Return: void
 */
void printop(stack_t **stack, unsigned int ln_num)
{
	if (stack == NULL || *stack == NULL)
		moreoferrors(6, ln_num);
	printf("%d\n", (*stack)->n);
}

/**
 * poptop - add node to stack
 * @stack: ptr to ptr pointing to top node of stack
 * @ln_num: line of opcode
 * Return: void
 */
void poptop(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		moreoferrors(7, ln_num);
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * nop - do nothing
 * @stack: ptr to ptr pointing to top node of stack
 * @ln_num: line of opcode
 * Return: void
 */
void nop(stack_t **stack, unsigned int ln_num)
{
	(void)stack;
	(void)ln_num;
}

/**
 * swap_nd - to swap the top two element in the stack
 * @stack: ptr to ptr pointing to top node of stack
 * @ln_num: line of opcode
 * Return: void
 */
void swap_nd(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreoferrors(8, ln_num, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
