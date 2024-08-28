#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int data[100];
  int front, rear;
} Queue;

void enqueue(Queue *q, int value)
{
  q->data[q->rear++] = value;
}

int dequeue(Queue *q)
{
  return q->data[q->front++];
}

bool is_empty(Queue *q)
{
  return q->front == q->rear;
}

typedef struct
{
  Queue *q1, *q2;
} Stack;

void push(Stack *s, int value)
{
  enqueue(s->q2, value);
  while (!is_empty(s->q1))
    enqueue(s->q2, dequeue(s->q1));

  Queue *temp = s->q1;
  s->q1 = s->q2;
  s->q2 = temp;
}

int pop(Stack *s)
{
  return dequeue(s->q1);
}