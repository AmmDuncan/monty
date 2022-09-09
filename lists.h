#ifndef LISTS_H
#define LISTS_H
#include "monty.h"
#include <ctype.h>

void push(stack_t **stack, unsigned int n);
int pop(stack_t **head, unsigned int index);
void print_stack(const stack_t *h);

void (*get_func(char *opcode))(stack_t **, unsigned int);
void invoke(char *command, unsigned int iarg, int line);
void check_error(char *opcode, char *arg, unsigned int iarg, int line, char *message);
void check_file_error(FILE *fptr, char *fname);
void free_stack(stack_t *h);

/* handlers */
void push_handler(stack_t **stack, unsigned int line);
void pall_handler(stack_t **stack, unsigned int line);
void pint_handler(stack_t **stack, unsigned int line);
void pop_handler(stack_t **stack, unsigned int line);
void nop_handler(stack_t **stack, unsigned int line);

#endif
