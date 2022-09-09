#include "lists.h"

/**
 * push_handler - handle push command
 * @stack: stack to work with
 * @line: line number
 */
void push_handler(_stack_t **stack, unsigned int line)
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
 * pop_handler - handle pop command
 * @stack: stack to work with
 * @line: line number
 */
void pop_handler(_stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	pop(stack, 0);
}

/**
 * swap_handler - handle swap command
 * @stack: stack to work with
 * @line: line number
 */
void swap_handler(_stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	swap(stack);
}

/**
 * add_handler - handle add command
 * @stack: stack to work with
 * @line: line number
 */
void add_handler(_stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	add(stack);
}

/**
 * sub_handler - handle sub command
 * @stack: stack to work with
 * @line: line number
 */
void sub_handler(_stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sub(stack);
}
