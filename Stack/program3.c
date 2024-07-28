#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define STACK_SIZE 50

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
  return value;
}

void to_binary(int num)
{
  while (num != 0)
  {
    push_to_stack(num % 2);
    num /= 2;
  }

  while (top != -1)
  {
    printf("%d", pop_from_stack());
  }
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
  }
  printf("\n");
}

int main()
{
  to_binary(1000);
}