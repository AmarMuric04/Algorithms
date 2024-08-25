#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
  int *array, size, capacity, top, rear;
} Queue;

Queue *init_q(int capacity)
{
  Queue *q = malloc(sizeof(Queue));
  q->array = malloc(sizeof(int) * capacity);
  q->capacity = capacity;
  q->top = q->rear = q->size = 0;

  return q;
}

bool is_full(Queue *q)
{
  return q->size == q->capacity;
}

void enque(Queue *q, int val)
{
  if (is_full(q))
  {
    printf("Full.");
    return;
  }

  if (val % 2 == 0)
  {
    q->array[q->rear] = val;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
  }
  else
    printf("Value isn't even.\n");
}

void print_it(Queue *q)
{
  for (int i = q->top; i < q->size; i++)
  {
    int index = i % q->capacity;
    printf("%d ", q->array[index]);
  }
  printf("\n");
}

int main()
{

  Queue *q = init_q(100);
  enque(q, 4);
  enque(q, 2);
  enque(q, 3);

  print_it(q);

  free(q);

  return 0;
}