#include "monty.h"

/**
 * op_file - open file
 * @file_name: file path
 * Return: void
 */
void op_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		errors(2, file_name);
	rd_file(fd);
	fclose(fd);
}

/**
 * rd_file - read file
 * @fd: pointer to file descriptor
 * Return: void
 */
void rd_file(FILE *fd)
{
	int ln_num, format = 0;
	char *buffer = NULL;
	size_t length = 0;

	for (ln_num = 1; getline(&buffer, &length, fd) != -1; ln_num++)
		format = parse_ln(buffer, ln_num, format);
	free(buffer);
}

/**
 * parse_ln - seprate each line into token to determine
 * which function to call
 * @buffer: line from file
 * @ln_num: line number
 * @format: storage format if 0 node enered as stack
 * 1 if node enter in queue
 * Return: return 0 in stack and 1 in queue
 */
int parse_ln(char *buffer, int ln_num, int format)
{
	char *opcode, *value;
	const char *delim = "\n";

	if (buffer == NULL)
		errors(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_fun(opcode, value, ln_num, format);
	return (format);
}

/**
 * find_fun - find the approperate func for the opcode
 * @opcode: opcode
 * @value: arg of opcode
 * @format: storage
 * @ln: line number
 * Return: void
 */
void find_fun(char *opcode, char *value, int ln, int format)
{
	int a;
	int flag;

	instruction_t func_list[] = {
		{"push", at_stack},
		{"pall", printstack},
		{"pint", printop},
		{"pop", poptop},
		{"nop", nop},
		{"swap", swap_nd},
		{"add", add_nd},
		{"sub", sub_nd},
		{"div", div_nd},
		{"mul", mul_nd},
		{"mod", mod_nd},
		{"pchar", printchar},
		{"pstr", printstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, a = 0; func_list[a].opcode != NULL; a++)
	{
		if (strcmp(opcode, func_list[a].opcode) == 0)
		{
			call_fun(func_list[a].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		errors(3, opcode);
}
