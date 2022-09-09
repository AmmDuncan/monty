#include "lists.h"

/**
 * add - handle adding elements
 *
 * @head: points to head of function
 */
void add(_stack_t **head)
{
	_stack_t *top = *head, *next = (*head)->next;
	int n = top->n + next->n;

	next->n = n;
	*head = next;

	free(top);
}

/**
 * sub - handle subing elements
 *
 * @head: points to head of function
 */
void sub(_stack_t **head)
{
	_stack_t *top = *head, *next = (*head)->next;
	int n = next->n - top->n;

	next->n = n;
	*head = next;

	free(top);
}

/**
 * div_stack - handle dividing elements
 *
 * @head: points to head of function
 */
void div_stack(_stack_t **head)
{
	_stack_t *top = *head, *next = (*head)->next;
	int n = next->n / top->n;

	next->n = n;
	*head = next;

	free(top);
}

/**
 * mul_stack - handle muliding elements
 *
 * @head: points to head of function
 */
void mul_stack(_stack_t **head)
{
	_stack_t *top = *head, *next = (*head)->next;
	int n = next->n * top->n;

	next->n = n;
	*head = next;

	free(top);
}

/**
 * mod_stack - handle modiding elements
 *
 * @head: points to head of function
 */
void mod_stack(_stack_t **head)
{
	_stack_t *top = *head, *next = (*head)->next;
	int n = next->n % top->n;

	next->n = n;
	*head = next;

	free(top);
}
