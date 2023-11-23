#include "stack.h"
#include <stdio.h>

int main(void) {
  Stack *stack = stack_init();
  stack_push(stack, 5);
  stack_push(stack, 6);
  stack_push(stack, 7);
  stack_push(stack, 8);

  while (!stack_is_empty(stack)) {
    stack_print(stack);
    printf("Popped: %d\n\n", stack_pop(stack));
  }
  stack_print(stack);

  stack_deinit(stack);
  return 0;
}
