#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue
{
  int front;
  int rear;
  int size;
  int *array;
  unsigned capacity;
};

bool is_empty(struct Queue *queue)
{
  return queue->size == 0;
}

bool is_full(struct Queue *queue)
{
  return queue->size == queue->capacity;
}

void enqueue(struct Queue *queue, int value)
{
  if (is_full(queue))
    return;

  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = value;
  queue->size++;

  printf("%d enqueued to the queue.\n", value);
}

int dequeue(struct Queue *queue)
{
  if (is_empty(queue))
    return INT_MIN;
  int item = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;

  printf("%d enqueued to the queue.\n", item);
  return item;
}

int front(struct Queue *queue)
{
  if (is_empty(queue))
    return INT_MIN;
  return queue->array[queue->front];
}

int rear(struct Queue *queue)
{
  if (is_empty(queue))
    return INT_MIN;
  return queue->array[queue->rear];
}

struct Queue *create_queue(unsigned capacity)
{
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = queue->size = 0;
  queue->rear = capacity - 1;
  queue->array = (int *)malloc(queue->capacity * sizeof(int));
  return queue;
}

int main()
{
  struct Queue *queue = create_queue(10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);
  enqueue(queue, 60);

  printf("The rear is %d\n", rear(queue));
  printf("The front is %d\n", front(queue));

  dequeue(queue);
  printf("The front is %d\n", front(queue));

  return 0;
}