#include "lists.h"

/**
 * add - handle adding elements
 *
 * @head: points to head of function
 */
void add(stack_t **head)
{
	stack_t *top = *head, *next = (*head)->next;
	int n = top->n + next->n;

	next->n = n;
	*head = next;

	free(top);
}
