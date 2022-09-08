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
		check_error(command, arg, iarg, line);
		push(&g_stack, iarg);
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

/***/
void check_error(char *opcode, char *arg, unsigned int iarg, int line)
{
	if (arg == NULL || (iarg == 0 && arg != NULL && arg[0] != '0'))
	{
		printf("L%d: usage: %s integer", line, opcode);
		exit(EXIT_FAILURE);
	}
}
