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
  Stack *s;
} Queue;

void enqueue(Queue *q, int value)
{
  Stack *s1 = malloc(sizeof(Stack));
  s1->top = -1;

  while (!isEmpty(q->s))
    push(s1, pop(q->s));

  push(s1, value);

  while (!isEmpty(s1))
    push(q->s, pop(s1));
}

void dequeue(Queue *q, int value)
{
  return pop(q->s);
}