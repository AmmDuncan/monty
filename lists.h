#ifndef LISTS_H
#define LISTS_H
#include "monty.h"
#include <ctype.h>

void print_stack(const stack_t *h);
void push(stack_t **stack, unsigned int n);
int pop(stack_t **head, unsigned int index);
void swap(stack_t **head);
void add(stack_t **head);
void sub(stack_t **head);

void (*get_func(char *opcode))(stack_t **, unsigned int);
void check_file_error(FILE *fptr, char *fname);
void free_stack(stack_t *h);

/* handlers */
void push_handler(stack_t **stack, unsigned int line);
void pall_handler(stack_t **stack, unsigned int line);
void pint_handler(stack_t **stack, unsigned int line);
void pop_handler(stack_t **stack, unsigned int line);
void nop_handler(stack_t **stack, unsigned int line);
void swap_handler(stack_t **stack, unsigned int line);
void add_handler(stack_t **stack, unsigned int line);
void sub_handler(stack_t **stack, unsigned int line);

#endif
