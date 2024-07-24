#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *link;
};

void count_of_nodes(struct node *head)
{
  int count = 0;
  if (head == NULL)
    printf("Linked List is empty!");
  struct node *ptr = NULL;
  ptr = head;
  while (ptr != NULL)
  {
    count++;
    ptr = ptr->link;
  }
  printf("%d", count);
}

int main()
{
  struct node *head = (struct node *)malloc(sizeof(struct node));
  head->data = 45;

  struct node *current = (struct node *)malloc(sizeof(struct node));
  current->data = 98;
  head->link = current;

  current = (struct node *)malloc(sizeof(struct node));
  current->data = 3;
  head->link->link = current;

  head->link->link->link = NULL;

  // printf("%d", head->link->data);

  count_of_nodes(head);

  return 0;
}