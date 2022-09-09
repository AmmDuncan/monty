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
	div(stack);
}
