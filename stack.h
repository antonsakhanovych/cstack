#ifndef STACK
#define STACK

#include <stdbool.h>

typedef struct stack Stack;

struct stack {
  void *_internal;
};

Stack *stack_init();

bool stack_is_empty(Stack *);

void stack_print(Stack *self);

void stack_push(Stack *self, int val);

int stack_top(Stack *self);

int stack_pop(Stack *self);

void *stack_deinit(Stack *self);

#endif
