#include <stdio.h>
#include <stdlib.h>

struct node
{
  struct node *prev;
  int val;
  struct node *next;
};

struct node *initialize(int val)
{
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->val = val;
  head->prev = NULL;
  head->next = NULL;

  return head;
}

struct node *get_tail(struct node *head)
{
  if (head == NULL)
  {
    printf("Initialize the list first.");
    return NULL;
  }
  struct node *tail = head;

  while (tail->next != NULL)
    tail = tail->next;

  return tail;
}

void add_element(struct node **tail, int val)
{
  if (*tail == NULL)
  {
    *tail = initialize(val);
    return;
  }
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->val = val;
  (*tail)->next = new_node;
  new_node->prev = *tail;
  new_node->next = NULL;
  *tail = new_node;
}

void print_dll(struct node *head)
{
  if (head == NULL)
  {
    printf("Initialize the list first.");
    return;
  }

  struct node *current = head;

  while (current != NULL)
  {
    printf("%d ", current->val);
    current = current->next;
  }
  printf("\n");
}

struct node *concatenate_dlls(struct node *first_head, struct node *first_tail, struct node *second_head)
{
  if (first_head == NULL || second_head == NULL)
  {
    printf("One of the lists is empty, please either initialize it or add elements.");
    return NULL;
  }
  struct node *new_head = first_head;
  first_tail->next = second_head;
  second_head->prev = first_tail;

  return new_head;
}

void clear_dll(struct node **head, struct node **tail)
{
  struct node *current = *head;
  struct node *temp;
  while (current != NULL)
  {
    temp = current->next;
    free(current);
    current = temp;
  }
  *head = NULL;
  *tail = NULL;
}

int main()
{
  struct node *head = initialize(200);
  struct node *tail = get_tail(head);

  add_element(&tail, 305);
  add_element(&tail, 405);
  add_element(&tail, 505);
  add_element(&tail, 605);

  struct node *head_2 = initialize(-200);
  struct node *tail_2 = get_tail(head_2);

  add_element(&tail_2, -305);
  add_element(&tail_2, -405);
  add_element(&tail_2, -505);
  add_element(&tail_2, -605);
  struct node *head_3 = concatenate_dlls(head, tail, head_2);
  struct node *tail_3 = get_tail(head_3);

  print_dll(head);
  print_dll(head_2);
  print_dll(head_3);

  clear_dll(&head, &tail);

  return 0;
}