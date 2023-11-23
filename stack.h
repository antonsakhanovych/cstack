#ifndef STACK
#define STACK

typedef struct stack Stack;

struct stack {
  int val;
  Stack *next;
};

void push(int val);

int top();

int pop();

#endif
