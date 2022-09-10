#include "lists.h"

/**
 * pall_handler - handle pall command
 * @stack: stack to work with
 * @line: line number
 */
void pall_handler(_stack_t **stack, unsigned int line)
{
	(void)line;

	print_stack(*stack);
}

/**
 * pint_handler - handle pint command
 * @stack: stack to work with
 * @line: line number
 */
void pint_handler(_stack_t **stack, unsigned int line)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop_handler - handle nop command
 * @stack: stack to work with
 * @line: line number
 */
void nop_handler(_stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
}

/**
 * pchar_handler - handle pchar command
 * @stack: stack to work with
 * @line: line number
 */
void pchar_handler(_stack_t **stack, unsigned int line)
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;

	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", n);
}

/**
 * pstr_handler - handle pstr command
 * @stack: stack to work with
 * @line: line number
 */
void pstr_handler(_stack_t **stack, unsigned int line)
{
	(void)line;

	if (*stack != NULL)
		print_stack_chr(*stack);
}
