#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

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

Queue *create_queue()
{
  Queue *queue = malloc(sizeof(Queue));
  queue->rear = queue->front = NULL;
  return queue;
}

bool is_empty(Queue *queue)
{
  return queue->front == NULL;
}

void enqueue(Queue *queue, int value)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->val = value;
  new_node->next = queue->rear;
  if (is_empty(queue))
  {
    queue->rear = new_node;
    queue->front = new_node;
  }
  else
  {
    queue->rear->next = new_node;
    queue->rear = new_node;
  }
}

int dequeue(Queue *queue)
{
  if (is_empty(queue))
  {
    printf("Underflow\n");
    return INT_MIN;
  }
  Node *temp = queue->front;
  int value = temp->val;
  queue->front = queue->front->next;
  free(temp);

  if (queue->front == NULL)
  {
    queue->rear = NULL;
    printf("Queue is now empty\n");
  }
  return value;
}

int front(Queue *queue)
{
  if (is_empty(queue))
  {
    printf("Empty\n");
    return INT_MIN;
  }
  return queue->front->val;
}

int rear(Queue *queue)
{
  if (is_empty(queue))
  {
    printf("Empty\n");
    return INT_MIN;
  }
  return queue->rear->val;
}
int main()
{
  Queue *queue = create_queue();
  enqueue(queue, 25);

  printf("Front is: %d\n", front(queue));
  printf("Rear is: %d\n", rear(queue));
  dequeue(queue);

  return 0;
}