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

/**
 * sub - handle subing elements
 *
 * @head: points to head of function
 */
void sub(stack_t **head)
{
	stack_t *top = *head, *next = (*head)->next;
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
void div_stack(stack_t **head)
{
	stack_t *top = *head, *next = (*head)->next;
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
void mul_stack(stack_t **head)
{
	stack_t *top = *head, *next = (*head)->next;
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
void mod_stack(stack_t **head)
{
	stack_t *top = *head, *next = (*head)->next;
	int n = next->n % top->n;

	next->n = n;
	*head = next;

	free(top);
}
