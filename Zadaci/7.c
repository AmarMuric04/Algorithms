#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue
{
  int *array, front, rear, size, capacity;

} Q;

Q *create_q(int capacity)
{
  Q *q = malloc(sizeof(Q));
  q->capacity = capacity;
  q->front = q->rear = q->size = 0;
  q->array = malloc(capacity * sizeof(int));

  return q;
}

void enque(Q *q, int val)
{
  if (val % 2 != 0)
  {
    printf("Error. Value must be even.\n");
    return;
  }

  q->array[q->rear++] = val;
}

int main()
{
  Q *q = create_q(100);
  enque(q, 4);
  return 0;
}