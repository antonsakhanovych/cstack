#include "./stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _internal_stack _Stack;

struct _internal_stack {
  int *data;
  size_t size;
  size_t cap;
};

Stack *stack_init() {
  _Stack *internal = malloc(sizeof(_Stack));
  internal->cap = 2;
  internal->data = calloc(2, sizeof(int));
  internal->size = 0;
  Stack *self = malloc(sizeof(Stack));
  self->_internal = internal;
  return self;
}

bool stack_is_empty(Stack *self) {
  _Stack *internal = self->_internal;
  return internal->size == 0;
}

void stack_print(Stack *self) {
  _Stack *internal = self->_internal;
  printf("[ ");
  for (size_t ind = 0; ind < internal->size; ind++) {
    printf("%d ", internal->data[ind]);
  }
  printf("]\n");
}

void stack_push(Stack *self, int val) {
  _Stack *internal = self->_internal;
  if (internal->size == internal->cap) {
    int *temp = internal->data;
    internal->cap *= 2;
    internal->data = calloc(internal->cap, sizeof(int));
    memcpy(internal->data, temp, internal->size * sizeof(int));
    free(temp);
  }
  internal->data[internal->size++] = val;
}

int stack_top(Stack *self) {
  _Stack *internal = self->_internal;
  return internal->data[internal->size - 1];
}

int stack_pop(Stack *self) {
  _Stack *internal = self->_internal;
  return internal->data[--internal->size];
}

void *stack_deinit(Stack *self) {
  _Stack *internal = self->_internal;
  free(internal->data);
  free(internal);
  free(self);
}
