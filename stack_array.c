#include "./stack.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node _Node;

struct _node {
  int val;
  _Node *next;
};

Stack *stack_init() {
  Stack *self = malloc(sizeof(Stack));
  self->top = NULL;
  return self;
}

void stack_print(Stack *self) {
  _Node *curr = self->top;
  printf("[ ");
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("]\n");
}

void stack_push(Stack *self, int val) {
  _Node *temp = self->top;
  _Node *node = malloc(sizeof(_Node));
  node->val = val;
  node->next = temp;
  self->top = node;
};

int stack_top(Stack *self) { return ((_Node *)self->top)->val; }

int stack_pop(Stack *self) {
  _Node *curr = (_Node *)self->top;
  self->top = curr->next;
  int res = curr->val;
  free(curr);
  return res;
}

void *stack_deinit(Stack *self) {
  _Node *curr = self->top;
  while (curr != NULL) {
    _Node *temp = curr->next;
    free(curr);
    curr = temp;
  }
  free(self);
}
