#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

size_t get_list_length(struct node *head)
{
  size_t count = 0;

  struct node *ptr = head;
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->link;
  }
  return count;
}

void print_data(struct node *head)
{
  if (head == NULL)
  {
    printf("Empty");
    return;
  }
  struct node *ptr = head;
  while (ptr != NULL)
  {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
  printf("\n");
}

struct node *create_head(int data)
{
  struct node *head = NULL;
  head = (struct node *)malloc(sizeof(struct node));
  head->link = NULL;
  head->data = data;

  return head;
}

void create_node(struct node **tail, int data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->link = NULL;

  (*tail)->link = new_node;
  *tail = new_node;
}

void free_list(struct node **head)
{
  struct node *current = *head;
  while (current != NULL)
  {
    struct node *next = current->link;
    free(current);
    current = next;
  }
  *head = NULL;
}

struct node *add_to_start(struct node **head, int data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->link = *head;
  new_node->data = data;

  *head = new_node;
  return *head;
}

void insert_node_at(struct node **head, struct node **tail, int position, int data)
{
  int length = get_list_length(*head);
  if (position < 0)
  {
    printf("Can't insert a node in a negative position.");
    return;
  }
  else if (position > length)
  {
    printf("Can't insert a node in the given position.");
    return;
  }
  else if (position == 0)
  {
    add_to_start(head, data);
    return;
  }
  else if (position == length)
  {
    create_node(tail, data);
    return;
  }
  else
  {
    struct node *current = *head;
    for (size_t i = 0; i < position - 1; ++i)
      current = current->link;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = current->link;
    current->link = new_node;
  }
}

void get_head(struct node *head)
{
  if (head == NULL || get_list_length(head) == 0)
  {
    printf("Head is not initialized, please use create_head().");
    return;
  }
  printf("The head of this Linked List is %d (points to #%p -> %d)\n", head->data, head->link, head->link->data);
}

void delete_first(struct node **head)
{
  if (*head == NULL)
    printf("List is already empty.");
  else
  {
    struct node *temp = *head;
    *head = (*head)->link;
    free(temp);
    temp->link = NULL;
  }
}

void delete_last(struct node *head, struct node **tail)
{
  struct node *temp = head;
  if (head == NULL)
  {
    printf("Linked list is already empty.");
    return;
  }

  while (temp->link->link != NULL)
  {
    temp = temp->link;
  }

  free(temp->link);
  temp->link = NULL;
  *tail = temp;
}

void delete_node_at(struct node **head, struct node **tail, int position)
{
  if (*head == NULL)
  {
    printf("Linked list is already empty.");
    return;
  }
  if (position == 0)
  {
    delete_first(head);
    return;
  }
  else if (position == get_list_length(*head))
  {
    delete_last(*head, tail);
    return;
  }
  else
  {
    struct node *current = *head;
    struct node *previous = *head;
    for (size_t i = 0; i < position; ++i)
    {
      previous = current;
      current = current->link;
    }
    previous->link = current->link;
    free(current);
    current = NULL;
  }
}

void reverse(struct node **head, struct node **tail)
{
  struct node *prev = NULL;
  struct node *current = *head;
  struct node *next = NULL;

  while (current != NULL)
  {
    next = current->link;
    current->link = prev;
    prev = current;
    current = next;
  }

  *tail = *head;
  *head = prev;
}

int main()
{
  struct node *head = create_head(1000);
  struct node *tail = head;
  create_node(&tail, 320);
  print_data(head);
  reverse(&head, &tail);
  print_data(head);

  free_list(&head);

  printf("The length of the Linked List is %zu\n", get_list_length(head));
  if (head == NULL)
    printf("List deleted successfully");

  return 0;
}

// Adding at start O(1)
// Adding at end O(1)
// Getting head O(1)
// Adding at given position O(position) to find position (at worst O(n - 1)) a)nd O(1 to insert
// Print list O(n)
// Freeing list O(n)