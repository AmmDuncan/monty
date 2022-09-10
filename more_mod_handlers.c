#include "lists.h"

/**
 * div_handler - handle div command
 * @stack: stack to work with
 * @line: line number
 */
void div_handler(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	div_stack(stack);
}

/**
 * mul_handler - handle mul command
 * @stack: stack to work with
 * @line: line number
 */
void mul_handler(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	mul_stack(stack);
}

/**
 * mod_handler - handle mod command
 * @stack: stack to work with
 * @line: line number
 */
void mod_handler(stack_t **stack, unsigned int line)
{
	if (*stack == NULL || (*stack && (*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	mod_stack(stack);
}

/**
 * pchar_handler - handle pchar command
 * @stack: stack to work with
 * @line: line number
 */
void pchar_handler(stack_t **stack, unsigned int line)
{
	int n;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;

	if (n < 0 || n > 255)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", n);
}
