#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *left, *right;
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

Node *
init_node(int val)
{
  Node *n = malloc(sizeof(Node));
  n->val = val;
  n->left = n->right = NULL;

  return n;
}

void prepend(Doubly **ll, int val)
{

  Node *n = init_node(val);

  if ((*ll)->head == NULL)
  {
    (*ll)->head = n;
    (*ll)->tail = n;
    return;
  }

  n->right = (*ll)->head;
  (*ll)->head->left = n;
  (*ll)->head = n;
}

void append(Doubly **ll, int val)
{
  Node *n = init_node(val);
  if ((*ll)->head == NULL)
  {
    (*ll)->head = n;
    (*ll)->tail = n;
    return;
  }

  n->left = (*ll)->tail;
  (*ll)->tail->right = n;
  (*ll)->tail = n;
}

void delete_node(Doubly **ll, int val_to_delete)
{
  Node *temp = (*ll)->head;

  while (temp != NULL && temp->val != val_to_delete)
    temp = temp->right;

  if (temp == NULL)
  {
    printf("The value wasn't found in the list.\n");
    return;
  }

  if (temp == (*ll)->head)
  {
    (*ll)->head = temp->right;
    if ((*ll)->head != NULL)
      (*ll)->head->left = NULL;
    else
      (*ll)->tail = NULL;
  }
  else if (temp == (*ll)->tail)
  {
    (*ll)->tail = temp->left;
    if ((*ll)->tail != NULL)
      (*ll)->tail->right = NULL;
    else
      (*ll)->head = NULL;
  }
  else
  {
    temp->left->right = temp->right;
    temp->right->left = temp->left;
  }

  free(temp);
}

void concatenate(Doubly **ll1, Doubly **ll2)
{
  Node *first_head = (*ll1)->head;
  Node *first_tail = (*ll1)->tail;
  Node *second_head = (*ll2)->head;
  Node *second_tail = (*ll1)->tail;

  if (first_head == NULL && second_head == NULL)
  {
    printf("Can't do that.");
    return;
  }

  if (second_head != NULL)
  {
    first_tail->right = second_head;
    first_tail = second_tail;
  }
}

void inverse_with_array(Doubly **ll)
{
  Node *temp = (*ll)->head;
  int size = 0;
  while (temp != NULL)
  {
    size++;
    temp = temp->right;
  }

  int *array = malloc(sizeof(int) * size);

  temp = (*ll)->head;
  for (int i = 0; i < size; i++)
  {
    array[i] = temp->val;
    temp = temp->right;
  }

  temp = (*ll)->head;
  for (int i = size - 1; i >= 0; i--)
  {
    temp->val = array[i];
    temp = temp->right;
  }
}

void print_it(Doubly *ll)
{
  Node *temp = ll->head;

  while (temp != NULL)
  {
    printf("%d, ", temp->val);
    temp = temp->right;
  }
  printf("\n");
}

int main()
{
  Doubly *dll = init_doubly();
  prepend(&dll, 100);
  prepend(&dll, 200);
  prepend(&dll, 300);
  prepend(&dll, 400);
  prepend(&dll, 500);

  Doubly *dll2 = init_doubly();
  prepend(&dll2, 600);
  prepend(&dll2, 700);
  prepend(&dll2, 800);
  prepend(&dll2, 900);
  concatenate(&dll, &dll2);

  print_it(dll);
  inverse_with_array(&dll);
  print_it(dll);

  while (dll->head != NULL)
    delete_node(&dll, dll->head->val);
  free(dll);

  return 0;
}
