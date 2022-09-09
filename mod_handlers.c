#include "lists.h"

/**
 * push_handler - handle push command
 * @stack: stack to work with
 * @line: line number
 */
void push_handler(stack_t **stack, unsigned int line)
{
	int iarg, pusherr = 0, i = 0;

	if (data->arg != NULL)
	{
		iarg = atoi(data->arg);
		for (i = 0; data->arg[i] != '\0'; i++)
			if (!isdigit(data->arg[i]) && data->arg[i] != '-')
				pusherr = 1;
	}

	if (data->arg == NULL ||
	    (iarg == 0 &&
	     data->arg != NULL &&
	     (strcmp(data->arg, "0") && strcmp(data->arg, "-0"))) ||
	    pusherr)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	push(stack, iarg);
}

/**
 * pall_handler - handle pall command
 * @stack: stack to work with
 * @line: line number
 */
void pall_handler(stack_t **stack, unsigned int line)
{
	(void)line;

	print_stack(*stack);
}
