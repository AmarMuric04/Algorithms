#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
  int data[MAX];
  int front, rear;
} Queue;

void enqueue(Queue *q, int value)
{
  if (q->rear == MAX - 1)
  {
    printf("Queue is full\n");
    return;
  }
  q->data[q->rear++] = value;
}

int dequeue(Queue *q)
{
  if (q->front == q->rear)
  {
    printf("Queue is empty\n");
    return -1;
  }
  return q->data[q->front++];
}

int isEmpty(Queue *q)
{
  return q->front == q->rear;
}

typedef struct
{
  Queue *q;
} Stack;

void push(Stack *s, int value)
{
  int size = s->q->front - s->q->rear;
  enqueue(s->q, value);

  for (int i = 0; i < size; i++)
    enqueue(s->q, dequeue(s->q));
}

void pop(Stack *s, int value)
{
  return dequeue(s->q);
}