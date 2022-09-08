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

	/*
	 * if (stack == NULL || new_node == NULL)
	 * return (NULL);
	 */

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
