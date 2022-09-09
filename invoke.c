#include "lists.h"
#include <ctype.h>

/**
 * invoke - take command and run code
 * @command: command to run
 * @arg: str argument
 * @iarg: int argument
 * @line: line number
 */
void invoke(char *command, char *arg, unsigned int iarg, int line)
{
	if (!strcmp(command, "push"))
	{
		check_error(command, arg, iarg, line, "usage: push integer");
		push(&g_stack, iarg);
	}
	else if (!strcmp(command, "pint"))
	{
		check_error(command, arg, iarg, line, "can't pint, stack empty");
		printf("%d\n", g_stack->n);
	}
	else if (!strcmp(command, "pop"))
	{
		check_error(command, arg, iarg, line, "can't pop an empty stack");
		pop(&g_stack, 0);
	}
	else if (!strcmp(command, "pall"))
		print_stack(g_stack);
	else if (!strcmp(command, "nop"))
		;
	else
	{
		char msg[100] = "unknown instruction ";

		strcat(msg, command);
		check_error(command, arg, iarg, line, msg);
	}
}

/**
 * check_error - check if error occured
 *
 * @opcode: name of command
 * @arg: string arg
 * @iarg: int arg
 * @line: line number
 * @message: custom error
 */
void check_error(char *opcode,
		 char *arg,
		 unsigned int iarg,
		 int line,
		 char *message)
{
	int i, pusherr = 0;

	if (!strcmp(opcode, "push") && arg != NULL)
		for (i = 0; arg[i] != '\0'; i++)
			if (!isdigit(arg[i]) && arg[i] != '-')
				pusherr = 1;

	if (
	    (!strcmp(opcode, "push") &&
	     (arg == NULL ||
	      (iarg == 0 && arg != NULL && (strcmp(arg, "0") && strcmp(arg, "-0"))) ||
	      pusherr)) ||
	    ((!strcmp(opcode, "pint") || !strcmp(opcode, "pop")) && g_stack == NULL))
	{
		fprintf(stderr, "L%d: %s\n", line, message);
		exit(EXIT_FAILURE);
	}
	if (message[0] == 'u' && message[1] == 'n' && message[2] == 'k')
	{
		fprintf(stderr, "L%d: %s\n", line, message);
		exit(EXIT_FAILURE);
	}
}

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
