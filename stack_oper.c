#include "monty.h"
/**
 * create_nd - creat node
 * @x: number to insert in the node
 * Return: if sucess return pointer to node or NULL
 */
stack_t *create_nd(int x)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
		errors(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = x;
	return (new_node);
}

/**
 * free_nd - to free nodes in the stack
 */
void free_nd(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * printstack - add node to stack
 * @stack: ptr to ptr pointing to the top node in the stack
 * @ln_num: line of the opcode
 * Return: void
 */
void printstack(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp;

	(void) ln_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * at_stack - add node to stack
 * @new_node: pointer to new node
 * @ln_num: present the line number in the opcode
 * Returm: void
 */
void at_stack(stack_t **new_node, __attribute__((unused))unsigned int ln_num)
{
	stack_t *temp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}
