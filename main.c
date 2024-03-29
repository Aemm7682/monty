#include "monty.h"
stack_t *head = NULL;
/**
 * main - entry point
 * @argc: arg count
 * @argv: list of argument
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(argv[1]);
	free_nd();
	return (0);
}
