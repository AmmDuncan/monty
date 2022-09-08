#include "lists.h"

/**
 * invoke - take command and run code
 * @command: command to run
 * @arg: str argument
 * @iarg: int argument
 * @line: line number
 */
void invoke(char *command, char *arg, unsigned int iarg, int line)
{
	/*int ind = 0;*/

	if (!strcmp(command, "push"))
	{
		check_error(command, arg, iarg, line, "usage: push integer");
		push(&g_stack, iarg);
	}
	if (!strcmp(command, "pint") && g_stack != NULL)
	{
		check_error(command, arg, iarg, line, "can't pint, stack empty");
		printf("%d\n", g_stack->n);
	}
	if (!strcmp(command, "pall"))
		print_stack(g_stack);

	/*
* while (switches[ind])
* {
* // void (*f)(stack_t **, unsigned int) = switches[ind]->f;

* if (switches[ind]->opcode == command)
* {
* printf("matched");
* // (*f)(&g_stack, *arg);
* }

* ind++;
* }
*/
}

/**
 * check_error - check if error occured
 *
 * @opcode: name of command
 * @arg: string arg
 * @iarg: int arg
 * @line: line number
 * @message: custom error message
 */
void check_error(char *opcode,
		 char *arg, unsigned int iarg, int line, char *message)
{
	if (
	    (!strcmp(opcode, "push") &&
	     (arg == NULL || (iarg == 0 && arg != NULL && arg[0] != '0'))) ||
	    (!strcmp(opcode, "pint") && g_stack == NULL))
	{
		fprintf(stderr, "L%d: %s\n", line, message);
		exit(EXIT_FAILURE);
	}
}
