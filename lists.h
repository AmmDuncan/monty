#ifndef LISTS_H
#define LISTS_H
#include "monty.h"

void push(stack_t **stack, unsigned int n);
void print_stack(const stack_t *h);

void invoke(char *command, char *arg, unsigned int iarg, int line);
void check_error(char *opcode, char *arg, unsigned int iarg, int line);

#endif
