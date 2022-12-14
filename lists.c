#include "lists.h"

/**
 * push - push number onto stack
 * @stack: pointer to stack
 * @n: number to push onto stack
 */
void push(_stack_t **stack, unsigned int n)
{
	_stack_t *new_node;

	new_node = (_stack_t *)malloc(sizeof(_stack_t));
	check_malloc(new_node);

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * print_stack - print linked list
 * @h: pionts to head node
 *
 * Description: print all elements in a doubly linked list
 * Return: size of list
 */
void print_stack(const _stack_t *h)
{
	size_t size;
	const _stack_t *cur_node;

	size = 0;
	cur_node = h;

	while (cur_node != NULL)
	{
		printf("%d\n", cur_node->n);
		cur_node = cur_node->next;
		size++;
	}
}

#include "lists.h"

/**
 * pop - remove node from list
 * @head: pionts to pointer to head
 * @index: position to remove item
 * Return: 1 if successful -1 if not
 */
int pop(_stack_t **head, unsigned int index)
{
	_stack_t *target, *prev, *dummy;
	unsigned int len = 0, count = 0;

	dummy = *head;
	target = *head;
	prev = NULL;
	if (head == NULL || *head == NULL)
		return (-1);
	while (dummy != NULL)
	{
		len++;
		dummy = dummy->next;
	}
	if (index >= len)
		return (-1);
	while (target != NULL && count != index)
	{
		count++;
		prev = target;
		target = target->next;
	}
	if (index == 0 && *head != NULL)
	{
		target = *head;
		*head = (*head)->next;
		free(target);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}
	if (count == index && target != NULL)
	{
		if (target->next != NULL)
			target->next->prev = prev;
		if (prev != NULL)
			target->prev->next = target->next;
		free(target);
		return (1);
	}
	return (-1);
}

/**
 * free_stack - free space used by list
 * @h: points to head of list
 */
void free_stack(_stack_t *h)
{
	_stack_t *cur, *holder;

	cur = h;

	while (cur != NULL)
	{
		holder = cur->next;
		free(cur);
		cur = holder;
	}
}

/**
 * swap - handle swaping elements
 *
 * @head: points to head of function
 */
void swap(_stack_t **head)
{
	_stack_t *top = *head, *next = (*head)->next;
	int n = (*head)->n;

	top->n = next->n;
	next->n = n;
}
