#include "monty.h"
/**
 * add_nd - add top two element of the stack
 * @stack: ptr to ptr pointing to the top node of stack
 * @ln_num: represent the line number of the opcode
 * Retuen: void
 */
void add_nd(stack_t **stack, unsigned int ln_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreoferrors(8, ln_num, "add");
	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub_nd - add top two element of the stack
 * @stack: ptr to ptr pointing to the top node of stack
 * @ln_num: represent the line number of the opcode
 * Retuen: void
 */
void sub_nd(stack_t **stack, unsigned int ln_num)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreoferrors(8, ln_num, "sub");
	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nd - add top two element of the stack
 * @stack: ptr to ptr pointing to the top node of stack
 * @ln_num: represent the line number of the opcode
 * Retuen: void
 */
void div_nd(stack_t **stack, unsigned int ln_num)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreoferrors(9, ln_num, "div");
	(*stack) = (*stack)->next;
	div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nd - add top two element of the stack
 * @stack: ptr to ptr pointing to the top node of stack
 * @ln_num: represent the line number of the opcode
 * Retuen: void
 */
void mul_nd(stack_t **stack, unsigned int ln_num)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreoferrors(8, ln_num, "mul");
	(*stack) = (*stack)->next;
	mul = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nd - add top two element of the stack
 * @stack: ptr to ptr pointing to the top node of stack
 * @ln_num: represent the line number of the opcode
 * Retuen: void
 */
void mod_nd(stack_t **stack, unsigned int ln_num)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		moreoferrors(8, ln_num, "mod");
	if ((*stack)->n == 0)
		moreoferrors(9, ln_num);
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
