#include "lists.h"

/**
 * invoke - take command and run code
 * @command: command to run
 * @arg: argument to pass with command
 */
void invoke(char *command, unsigned int *arg)
{
	/*int ind = 0;*/

	if (!strcmp(command, "push"))
		push(&g_stack, *arg);
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
