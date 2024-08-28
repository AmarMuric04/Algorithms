#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool is_empty(Stack *s)
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
  if (is_empty(q->s2))
  {
    if (is_empty(q->s1))
      return -1;
    while (!is_empty(q->s1))
      push(q->s2, pop(q->s1));

    return pop(q->s2);
  }
}