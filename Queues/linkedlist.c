#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct node
{
  int val;
  struct node *next;
} Node;

typedef struct queue
{
  Node *rear;
  Node *front;
} Queue;

int main()
{
  return 0;
}