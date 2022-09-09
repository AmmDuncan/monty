#include "lists.h"

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

/**
 * pint_handler - handle pint command
 * @stack: stack to work with
 * @line: line number
 */
void pint_handler(stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pint_handler - handle pint command
 * @stack: stack to work with
 * @line: line number
 */
void nop_handler(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}
