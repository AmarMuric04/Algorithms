#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct queue
{
  int *array, size, front, rear;
  unsigned capacity;
} Queue;

Queue *create_queue(unsigned capacity)
{
  Queue *q = malloc(sizeof(Queue));
  q->front = q->rear = q->size = 0;
  q->capacity = capacity;
  q->array = (int *)malloc(capacity * sizeof(int));

  return q;
}

bool is_empty(Queue *q)
{
  return q->size == 0;
}

bool is_full(Queue *q)
{
  return q->size == q->capacity;
}

void enqueue(Queue *q, int data)
{
  if (is_full(q))
  {
    printf("Queue overflow\n");
    return;
  }
  q->array[q->rear] = data;
  q->rear = (q->rear + 1) % q->capacity;
  q->size++;
}

int dequeue(Queue *q)
{
  if (is_empty(q))
  {
    printf("Queue underflow\n");
    return INT_MIN;
  }

  int popped = q->array[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->size--;
  return popped;
}

Queue *divisble_by_2022()
{
  int limit = 2022 * 8;
  Queue *q = create_queue(100);

  for (int i = 2022; i < limit; i += 2022)
    enqueue(q, i);

  return q;
}

Queue *divisible_by_5(Queue *q)
{
  Queue *q2 = create_queue(q->capacity);

  for (int i = 0; i < q->size; i++)
  {
    int index = (q->front + i) % q->capacity;
    if (q->array[index] % 5 == 0)
    {
      enqueue(q2, q->array[index]);
    }
  }

  return q2;
}

void print(Queue *q)
{
  if (is_empty(q))
  {
    printf("Queue is empty\n");
    return;
  }

  int i;
  for (i = 0; i < q->size; i++)
  {
    int index = (q->front + i) % q->capacity;
    printf("%d ", q->array[index]);
  }
  printf("\n");
}

int main()
{
  Queue *q1 = divisble_by_2022();
  print(q1);

  Queue *q2 = divisible_by_5(q1);
  print(q2);

  return 0;
}