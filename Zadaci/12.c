#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next, *prev;
} Node;

typedef struct doubly
{
  Node *head, *tail;
} Doubly;

Doubly *init_doubly()
{
  Doubly *d = malloc(sizeof(Doubly));
  d->head = d->tail = NULL;

  return d;
}

Node *init_node(int value)
{
  Node *n = malloc(sizeof(Node));
  n->val = value;
  n->next = n->prev = NULL;

  return n;
}

void prepend(Doubly **ll, int value)
{
  Node *n = init_node(value);

  if ((*ll)->head == NULL)
  {
    (*ll)->head = (*ll)->tail = n;
    return;
  }

  n->next = (*ll)->head;
  (*ll)->head = n;
  (*ll)->head->prev = n;
}

void print_odds(Doubly *ll)
{
  Node *temp = ll->head;

  while (temp != NULL)
  {
    printf("The number is: %d\n", temp->val);
    if (temp->val % 2 == 0)
      printf("The number is not odd");
    else
      printf("The number is odd");
    temp = temp->next;
    printf("\n");
  }
}

int main()
{
  Doubly *dll = init_doubly();
  prepend(&dll, 1);
  prepend(&dll, 2);
  prepend(&dll, 3);
  prepend(&dll, 4);
  prepend(&dll, 5);
  prepend(&dll, 7);

  print_odds(dll);

  return 0;
}