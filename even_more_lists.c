#include "lists.h"

/**
 * print_stack_chr - print linked list as string
 * @h: pionts to head node
 *
 * Description: print all elements in a doubly linked list
 * Return: size of list
 */
void print_stack_chr(const _stack_t *h)
{
	size_t size;
	const _stack_t *cur_node;
	int n, ran = 0;

	size = 0;
	cur_node = h;
	n = cur_node->n;

	while (cur_node != NULL && n < 127 && n > 0)
	{
		ran = 1;
		printf("%c", cur_node->n);
		cur_node = cur_node->next;
		size++;
		if (cur_node != NULL)
			n = cur_node->n;
	}

	if (ran == 1)
		printf("\n");
}
