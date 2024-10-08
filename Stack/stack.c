#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define STACK_SIZE 4

int stack_arr[STACK_SIZE];
int top = -1;

bool is_empty()
{
  if (top == -1)
    return true;
  return false;
}

bool is_full()
{
  if (top == STACK_SIZE - 1)
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
  printf("Adding %d...\n", data);
  stack_arr[top] = data;
}

int pop_from_stack()
{
  if (is_empty())
  {
    printf("Can't remove an element, stack is empty.\n");
    exit(1);
  }
  int value = stack_arr[top];

  top--;
  printf("Removing %d...\n", value);
  return value;
}

void print_stack()
{
  if (is_empty())
  {
    printf("Can't print the stack, it's empty.\n");
    return;
  }
  for (size_t i = 0; i <= top; ++i)
  {
    printf("%d", stack_arr[i]);
    if (i < top)
      printf(" - ");
  }
  printf("\n");
}

int main()
{
  int data;
  push_to_stack(1);
  push_to_stack(2);
  push_to_stack(3);
  push_to_stack(4);
  push_to_stack(5);
  push_to_stack(6);
  data = pop_from_stack();
  data = pop_from_stack();
  data = pop_from_stack();
  print_stack();
  return 0;
}
// 8lvgccryq