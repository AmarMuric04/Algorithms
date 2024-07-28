#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  int data;
  struct node *next;
} *top = NULL;

bool is_empty()
{
  return top == NULL;
}

bool is_full()
{
  struct node *temp = malloc(sizeof(struct node));
  if (temp == NULL)
    return true;

  free(temp);
  return false;
}

void push_to_llstack(int data)
{
  if (is_full())
  {
    printf("Stack overflow.\n");
    exit(1);
  }
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->next = top;
  new_node->data = data;
  top = new_node;
}

int pop_from_llstack()
{
  if (is_empty())
  {
    printf("Stack underflow.\n");
    exit(1);
  }

  struct node *temp = top;
  int value = temp->data;

  top = top->next;
  free(temp);
  temp = NULL;

  return value;
}

void print_llstack()
{
  if (is_empty())
  {
    printf("Can't print, llstack is empty.\n");
    exit(1);
  }
  struct node *current = top;

  while (current != NULL)
  {
    printf("%d", current->data);
    if (current->next != NULL)
      printf(" - ");
    current = current->next;
  }
}

int main()
{
  push_to_llstack(305);
  push_to_llstack(405);
  push_to_llstack(505);
  push_to_llstack(605);
  push_to_llstack(705);
  int data = pop_from_llstack();

  print_llstack();

  return 0;
}