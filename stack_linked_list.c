#include "./stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _node _Node;

struct _node {
  int val;
  _Node *next;
};

bool stack_is_empty(Stack *self) { return self->_internal == NULL; }

Stack *stack_init() {
  Stack *self = malloc(sizeof(Stack));
  self->_internal = NULL;
  return self;
}

void stack_print(Stack *self) {
  _Node *curr = self->_internal;
  printf("[ ");
  while (curr != NULL) {
    printf("%d ", curr->val);
    curr = curr->next;
  }
  printf("]\n");
}

void stack_push(Stack *self, int val) {
  _Node *temp = self->_internal;
  _Node *node = malloc(sizeof(_Node));
  node->val = val;
  node->next = temp;
  self->_internal = node;
};

int stack_top(Stack *self) { return ((_Node *)self->_internal)->val; }

int stack_pop(Stack *self) {
  _Node *curr = (_Node *)self->_internal;
  self->_internal = curr->next;
  int res = curr->val;
  free(curr);
  return res;
}

void *stack_deinit(Stack *self) {
  _Node *curr = self->_internal;
  while (curr != NULL) {
    _Node *temp = curr->next;
    free(curr);
    curr = temp;
  }
  free(self);
}
