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
  Stack *s;
} Queue;

void enqueue(Queue *q, int value)
{
  Stack *s2;
  s2->top = -1;

  while (!is_empty(q->s))
    push(s2, value);

  push(s2, value);

  while (!is_empty(s2))
    push(q->s, value);
}

int main()
{
  return 0;
}