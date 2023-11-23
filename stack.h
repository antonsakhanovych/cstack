#ifndef STACK
#define STACK

typedef struct stack Stack;

struct stack {
  void *top;
};

Stack *stack_init();

void stack_print(Stack *self);

void stack_push(Stack *self, int val);

int stack_top(Stack *self);

int stack_pop(Stack *self);

void *stack_deinit(Stack *self);

#endif
