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
  Queue q1, q2;
} Stack;

void push(Stack *s, int value)
{
  enqueue(&s->q2, value);
  while (!isEmpty(&s->q1))
  {
    enqueue(&s->q2, dequeue(&s->q1));
  }

  // Swap the queues
  Queue temp = s->q1;
  s->q1 = s->q2;
  s->q2 = temp;
}

int pop(Stack *s)
{
  if (isEmpty(&s->q1))
  {
    printf("Stack is empty\n");
    return -1;
  }
  return dequeue(&s->q1);
}

int main()
{
  Stack s;
  s.q1.front = s.q1.rear = 0;
  s.q2.front = s.q2.rear = 0;

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  printf("Popped: %d\n", pop(&s));
  printf("Popped: %d\n", pop(&s));

  return 0;
}
