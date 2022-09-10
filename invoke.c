#include "lists.h"
#include <ctype.h>

/**
 * check_malloc - check if malloc failed
 * @ptr: point to allocated address
 */
void check_malloc(void *ptr)
{
	if (ptr == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * get_func - select appropriate func
 * @opcode: command to match against function
 * Return: pointer to function if found, else NULL
 */
void (*get_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t func_list[] = {
	    {"push", push_handler},
	    {"pall", pall_handler},
	    {"pint", pint_handler},
	    {"pop", pop_handler},
	    {"nop", nop_handler},
	    {"swap", swap_handler},
	    {"add", add_handler},
	    {"sub", sub_handler},
	    {"div", div_handler},
	    {"mul", mul_handler},
	    {"mod", mod_handler},
	    {NULL, NULL}};
	int i = 0, len = 11;

	if (opcode[0] == '#')
		return (nop_handler);

	for (; i < len; i++)
	{
		if (!strcmp(func_list[i].opcode, opcode))
		{
			return (func_list[i].f);
		}
	}

	return (NULL);
}
