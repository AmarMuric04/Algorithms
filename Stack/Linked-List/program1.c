#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  int data;
  struct node *next;
};

bool is_empty(struct node *top)
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

void push_to_llstack(struct node **top, int data)
{
  if (is_full())
  {
    printf("Stack overflow.\n");
    exit(1);
  }
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->next = *top;
  new_node->data = data;
  *top = new_node;
}

int pop_from_llstack(struct node **top)
{
  if (is_empty(*top))
  {
    printf("Stack underflow.\n");
    exit(1);
  }

  struct node *temp = *top;
  int value = temp->data;

  *top = (*top)->next;
  free(temp);
  temp = NULL;

  return value;
}

void print_llstack(struct node *top)
{
  if (is_empty(top))
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

void reverse_stack(struct node **top)
{
  struct node *top_1 = NULL;
  struct node *top_2 = NULL;

  while (*top)
    push_to_llstack(&top_1, pop_from_llstack(top));
  while (top_1)
    push_to_llstack(&top_2, pop_from_llstack(&top_1));
  while (top_2)
    push_to_llstack(top, pop_from_llstack(&top_2));
}

int main()
{
  struct node *top_1 = NULL;
  struct node *top_2 = NULL;
  struct node *top_3 = NULL;
  push_to_llstack(&top_1, 305);
  push_to_llstack(&top_1, 405);
  push_to_llstack(&top_1, 505);
  push_to_llstack(&top_1, 605);
  push_to_llstack(&top_1, 705);

  print_llstack(top_1);

  reverse_stack(&top_1);

  print_llstack(top_1);

  return 0;
}