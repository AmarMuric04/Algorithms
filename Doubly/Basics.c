#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

size_t get_list_length(struct node *head)
{
  size_t count = 0;
  while (head != NULL)
  {
    count++;
    head = head->next;
  }
  return count;
}

void create_head(struct node **head, int data)
{
  if (*head != NULL)
  {
    printf("Head is already initialized.");
    return;
  }
  else
  {
    struct node *new_head = (struct node *)malloc(sizeof(struct node));
    new_head->prev = NULL;
    new_head->data = data;
    new_head->next = NULL;
    *head = new_head;
  }
}

void add_to_start(struct node **head, int data)
{
  struct node *new_node = malloc(sizeof(struct node));
  new_node->prev = NULL;
  new_node->data = data;
  new_node->next = (*head);
  (*head)->prev = new_node;
  *head = new_node;
}

void add_to_end(struct node **tail, int data)
{
  struct node *new_node = malloc(sizeof(struct node));
  (*tail)->next = new_node;
  new_node->prev = (*tail);
  new_node->data = data;
  new_node->next = NULL;
  *tail = new_node;
}

void add_at(struct node **head, struct node **tail, int position, int data)
{
  int length = get_list_length(*head);
  if (position < 0)
  {
    printf("Can't insert a node in a negative position.\n");
    return;
  }
  else if (position > length)
  {
    printf("Can't insert a node in the given position.\n");
    return;
  }
  else if (position == 0)
  {
    add_to_start(head, data);
    return;
  }
  else if (position == length)
  {
    add_to_end(tail, data);
    return;
  }
  else
  {
    struct node *current = *head;
    for (size_t i = 0; i < position - 1; ++i)
    {
      current = current->next;
    }
    struct node *current2 = current->next;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = current2;
    new_node->prev = current;
    current->next = new_node;
    current2->prev = new_node;
  }
}

void print_nodes(struct node *head)
{
  struct node *current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  struct node *head = NULL;
  create_head(&head, 100);
  struct node *tail = head;

  add_to_start(&head, 15);
  add_to_start(&head, 25);
  add_to_start(&head, 35);
  add_to_start(&head, 45);
  add_to_start(&head, 55);
  add_to_end(&tail, 25);
  add_to_end(&tail, 40);
  add_at(&head, &tail, -1, 100);

  print_nodes(head);

  printf("%d", get_list_length(head));

  return 0;
}