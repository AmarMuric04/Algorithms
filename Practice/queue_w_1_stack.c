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

void enqueue(Stack *s1, int value)
{
  Stack *s2;
  s2->top = -1;

  while (s1->top != -1)
    push(s2, pop(s1));

  push(s1, value);

  while (s2->top != -1)
    push(s2, pop(s1));
}

int dequeue(Stack *s)
{
  if (isEmpty(s))
    return 0;

  return pop(s);
}