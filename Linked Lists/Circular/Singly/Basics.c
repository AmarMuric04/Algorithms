#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  int data;
  struct node *next;
};

void add_to_start(struct node **tail, int data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = (*tail)->next;

  (*tail)->next = new_node;
};

void add_to_end(struct node **tail, int data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = (*tail)->next;

  (*tail)->next = new_node;

  *tail = new_node; // +
}

void print_node(struct node *tail)
{
  struct node *current = tail->next;
  do
  {
    printf("%d ", current->data);
    current = current->next;
  } while (current != tail->next);
  printf("\n");
}

void clear_list(struct node **tail)
{
  if (*tail == NULL)
    return;

  struct node *current = (*tail)->next;
  struct node *next_node = NULL;
  (*tail)->next = NULL;

  while (current != NULL)
  {
    next_node = current->next;
    free(current);
    current = next_node;
  }

  *tail = NULL;
}

void add_at(struct node **tail, size_t position, int data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->data = data;

  if (*tail == NULL)
  {
    new_node->next = new_node;
    *tail = new_node;
    return;
  }

  struct node *current = (*tail)->next;
  struct node *prev = NULL;

  size_t curr_position = 0;
  while (curr_position < position - 1 && current != *tail)
  {
    prev = current;
    current = current->next;
    curr_position++;
  }

  if (curr_position == 0)
  {
    printf("\nInserting the element in the first position.\n");
    add_to_start(tail, data);
    free(new_node);
  }
  else if (current == *tail)
  {
    printf("\nInserting the element in the last position.\n");
    add_to_end(tail, data);
    free(new_node);
  }
  else
  {
    printf("\nInserting the element somewhere in the middle.\n");
    new_node->next = current;
    prev->next = new_node;
  }
}

void delete_first(struct node **tail)
{
  if (*tail == NULL)
  {
    printf("CSLL already empty.");
    return;
  }
  if ((*tail)->next == *tail)
  {
    free(*tail);
    return;
  }

  struct node *temp = (*tail)->next;
  (*tail)->next = (*tail)->next->next;
  free(temp);
}

void delete_last(struct node **tail)
{
  if (*tail == NULL)
  {
    printf("CSLL already empty.");
    return;
  }
  if ((*tail)->next == *tail)
  {
    free(*tail);
    return;
  }

  struct node *current = (*tail)->next;

  while (current->next != *tail)
  {
    current = current->next;
  }
  current->next = (*tail)->next;
  free(*tail);
  (*tail) = current;
}

void delete_at(struct node **tail, int position)
{
  if (*tail == NULL)
  {
    printf("CSLL is already empty, can not perform deletion.");
    return;
  }

  if (position == 0)
  {
    delete_first(tail);
    return;
  }

  struct node *prev = NULL;
  struct node *current = (*tail)->next;

  size_t curr_position = 0;

  while (curr_position < position - 1 && current->next != (*tail)->next)
  {
    prev = current;
    current = current->next;
    curr_position++;
  }
  if (current->next == (*tail)->next)
  {
    delete_last(tail);
    return;
  }

  if (current == *tail)
  {
    delete_last(tail);
  }
  else
  {
    prev->next = current->next;
    free(current);
  }
}

size_t get_csll_length(struct node *tail)
{
  if (tail == NULL)
  {
    printf("Empty.");
    return 0;
  }

  struct node *current = tail;

  size_t length = 0;
  do
  {
    length++;
    current = current->next;
  } while (current != tail);

  return length;
}

struct node *create_csll()
{

  int length, data;
  printf("How long do you want your csll to be?: ");
  scanf("%d", &length);
  if (length == 0 || length < 0)
  {
    printf("Goodbye!\n");
    return NULL;
  }
  struct node *tail = (struct node *)malloc(sizeof(struct node));
  printf("Element no.1: ");
  scanf("%d", &data);
  tail->data = data;
  tail->next = tail;

  for (size_t i = 1; i < length; ++i)
  {
    printf("Element no.%d: ", i + 1);
    scanf("%d", &data);
    add_to_end(&tail, data);
  }

  printf("\nThis is what your csll looks like:\n");
  print_node(tail);

  char answer[10];
  printf("Would you like to add something to the start?\n");
  scanf("%9s", answer);
  if (strcmp("yes", answer) == 0)
  {
    printf("Enter the value: ");
    scanf("%d", &data);
    add_to_start(&tail, data);
  }
  printf("Would you like to add something to the end?\n");
  scanf("%s", &answer);
  if (strcmp("yes", answer) == 0)
  {
    printf("Enter the value: ");
    scanf("%d", &data);
    add_to_end(&tail, data);
  }

  printf("\nThis is what it looks like now:\n");
  print_node(tail);

  return tail;
}

int main()
{
  struct node *tail = create_csll();
  delete_at(&tail, 10);
  print_node(tail);

  size_t length = get_csll_length(tail);

  printf("%d", length);
  clear_list(&tail);

  if (tail == NULL)
    printf("CSLL deleted successfully!");
  return 0;
}