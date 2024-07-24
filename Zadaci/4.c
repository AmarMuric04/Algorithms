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

int sum_of_max_min(struct node *head)
{
  if (head == NULL)
  {
    printf("Initialize the list first or add elements to it.");
    return 0;
  }
  struct node *current = head;

  int max = current->val;
  int min = current->val;
  while (current != NULL)
  {
    if (current->val > max)
      max = current->val;
    if (current->val < min)
      min = current->val;
    current = current->next;
  }
  int sum = max + min;

  return sum;
}

int main()
{
  struct node *head = initialize(200);
  struct node *tail = get_tail(head);

  add_element(&tail, 305);
  add_element(&tail, 405);
  add_element(&tail, 505);
  add_element(&tail, 605);
  add_element(&tail, 705);
  add_element(&tail, 805);
  add_element(&tail, 905);

  struct node *head_2 = initialize(-200);
  struct node *tail_2 = get_tail(head_2);

  add_element(&tail_2, -305);
  add_element(&tail_2, -405);
  add_element(&tail_2, -505);
  add_element(&tail_2, -605);
  print_dll(head);

  int value = sum_of_max_min(head);
  int value_2 = sum_of_max_min(head_2);
  printf("%d\n", value);
  printf("%d\n", value_2);

  print_dll(head_2);

  clear_dll(&head, &tail);
  clear_dll(&head_2, &tail_2);

  return 0;
}