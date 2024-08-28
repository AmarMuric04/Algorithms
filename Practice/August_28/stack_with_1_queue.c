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
  Queue *q;
} Stack;

void push(Stack *s, int value)
{
  int size = s->q->rear - s->q->front;
  enqueue(s->q, value);

  for (int i = 0; i < size; i++)
    enqueue(s->q, dequeue(s->q));
}

int main()
{
  return 0;
}