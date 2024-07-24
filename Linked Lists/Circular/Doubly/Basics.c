#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

void add_to_empty(struct node **tail, int data)
{
  (*tail)->data = data;
  (*tail)->prev = *tail;
  (*tail)->next = *tail;
}

void add_to_start(struct node **tail, int data)
{
  if (*tail == NULL)
  {
    add_to_empty(tail, data);
    return;
  }

  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->data = data;

  new_node->next = (*tail)->next;
  new_node->prev = *tail;
  (*tail)->next->prev = new_node;
  (*tail)->next = new_node;
}

void add_to_end(struct node **tail, int data)
{
  if (*tail == NULL)
  {
    add_to_empty(tail, data);
    return;
  }

  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->data = data;
  new_node->next = (*tail)->next;
  new_node->prev = *tail;
  *tail = new_node;
}

void print_cdll(struct node *tail)
{
  if (tail == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  struct node *current = tail->next;
  if (current == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  do
  {
    printf("%d ", current->data);
    current = current->next;
  } while (current != tail->next);

  printf("\n");
}

void clear_cdll(struct node **tail)
{
  if (*tail == NULL)
  {
    printf("Already empty");
    return;
  }

  struct node *current = (*tail)->next;
  struct node *next_node;

  (*tail)->next = NULL;
  if (current != NULL)
  {
    current->prev = NULL;
  }

  while (current != NULL)
  {
    next_node = current->next;
    free(current);
    current = next_node;
  }

  *tail = NULL;
}

int main()
{
  struct node *tail = (struct node *)malloc(sizeof(struct node));

  add_to_empty(&tail, 205);
  add_to_start(&tail, 100);
  add_to_end(&tail, 300);

  print_cdll(tail);
  clear_cdll(&tail);

  if (tail == NULL)
    printf("CDLL deleted successfully!");

  return 0;
}