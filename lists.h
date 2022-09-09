#ifndef LISTS_H
#define LISTS_H
#include "monty.h"
#include <ctype.h>

void print_stack(const _stack_t *h);
void push(_stack_t **stack, unsigned int n);
int pop(_stack_t **head, unsigned int index);
void swap(_stack_t **head);
void add(_stack_t **head);
void sub(_stack_t **head);
void div_stack(_stack_t **head);
void mul_stack(_stack_t **head);

void (*get_func(char *opcode))(_stack_t **, unsigned int);
void check_file_error(FILE *fptr, char *fname);
void free_stack(_stack_t *h);

/* handlers */
void push_handler(_stack_t **stack, unsigned int line);
void pall_handler(_stack_t **stack, unsigned int line);
void pint_handler(_stack_t **stack, unsigned int line);
void pop_handler(_stack_t **stack, unsigned int line);
void nop_handler(_stack_t **stack, unsigned int line);
void swap_handler(_stack_t **stack, unsigned int line);
void add_handler(_stack_t **stack, unsigned int line);
void sub_handler(_stack_t **stack, unsigned int line);
void div_handler(_stack_t **stack, unsigned int line);
void mul_handler(_stack_t **stack, unsigned int line);

#endif
