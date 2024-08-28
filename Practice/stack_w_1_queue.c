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
  Queue q;
} Stack;

void push(Stack *s, int value)
{
  int size = s->q.rear - s->q.front;
  enqueue(&s->q, value);
  for (int i = 0; i < size; i++)
    enqueue(&s->q, dequeue(value));
}

int pop(Stack *s)
{
  if (isEmpty(&s->q))
  {
    printf("Stack is empty.\n");
    return -1;
  }

  return dequeue(&s->q);
}

int main()
{
  Stack s;
  s.q.front = s.q.rear = 0;

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  printf("Popped: %d\n", pop(&s));
  printf("Popped: %d\n", pop(&s));

  return 0;
}