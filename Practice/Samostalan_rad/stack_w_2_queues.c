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
  Queue *q1, *q2;
} Stack;

void push(Stack *s, int value)
{
  enqueue(s->q1, value);
  while (!isEmpty(s->q1))
    enqueue(s->q2, dequeue(s->q1));

  Queue *temp = s->q1;
  s->q1 = s->q2;
  s->q2 = temp;
}
