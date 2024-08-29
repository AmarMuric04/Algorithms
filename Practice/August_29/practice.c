#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int data[100];
  int top;
} Stack;

void push(Stack *s, int value)
{
  s->data[++s->top] = value;
}

int pop(Stack *s)
{
  return s->data[s->top--];
}

int isEmpty(Stack *s)
{
  return s->top == -1;
}

typedef struct
{
  Stack *s1, *s2;
} Queue;

void enqueue(Queue *q, int value)
{
  push(q->s1, value);
}

int dequeue(Queue *q)
{
  if (isEmpty(q->s2))
  {
    if (isEmpty(q->s1))
      return -1;

    while (!isEmpty(q->s1))
      push(q->s2, pop(q->s1));

    return pop(q->s2);
  }
}