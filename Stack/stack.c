#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 4

int stack_arr[STACK_SIZE];
int top = -1;

bool is_full()
{
  if (top + 1 == STACK_SIZE)
    return true;
  return false;
}

void push_to_stack(int data)
{
  if (is_full())
  {
    printf("Can't add %d, stack is full!\n", data);
    return;
  }
  top++;
  stack_arr[top] = data;
}

void print_stack()
{
  for (size_t i = 0; i <= top - 1; ++i)
    printf("%d - ", stack_arr[i]);
  printf("%d", stack_arr[top]);
  printf("\n");
}

int main()
{
  push_to_stack(1);
  push_to_stack(2);
  push_to_stack(3);
  push_to_stack(4);
  push_to_stack(5);
  push_to_stack(6);
  print_stack();

  return 0;
}