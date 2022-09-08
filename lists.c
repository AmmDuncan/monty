#include "lists.h"

/**
 * push - push number onto stack
 * @stack: pointer to stack
 * @n: number to push onto stack
 */
void push(stack_t **stack, unsigned int n)
{
	stack_t *new_node;

	new_node = (stack_t *)malloc(sizeof(stack_t));
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
void print_stack(const stack_t *h)
{
	size_t size;
	const stack_t *cur_node;

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
int pop(stack_t **head, unsigned int index)
{
	stack_t *target, *prev, *dummy;
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
