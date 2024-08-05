#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_HASH_SIZE 17
#define EMPTY INT_MIN

typedef struct hash
{
  int *array, capacity;
} Hash;

Hash *init_hash()
{
  Hash *h = malloc(sizeof(Hash));
  h->array = malloc(MAX_HASH_SIZE * sizeof(int));
  h->capacity = MAX_HASH_SIZE;

  for (int i = 0; i < MAX_HASH_SIZE; i++)
    h->array[i] = EMPTY;

  return h;
}

bool is_full(Hash *h)
{
  for (int i = 0; i < MAX_HASH_SIZE; i++)
    if (h->array[i] = EMPTY)
      return false;
  return true;
}

int hash(int key)
{
  return key % MAX_HASH_SIZE;
}

void insert(Hash *h, int key, int data)
{
  if (is_full(h))
  {
    printf("Hash table is full.\n");
    return;
  }
  int index = hash(key);
  if (h->array[index] != EMPTY && h->array[index] != data)
    printf("Collision happened with %d.\nFinding another spot...\n", data);
  while (h->array[index] != EMPTY)
    index = (index + 1) % h->capacity;

  h->array[index] = data;
}

int main()
{
  Hash *h = init_hash();
  int array[9] = {16, 41, 22, 44, 59, 32, 31, 73, 48};
  for (int i = 0; i < 9; i++)
    insert(h, array[i], array[i]);

  for (int i = 0; i < MAX_HASH_SIZE; i++)
    printf("%d ", h->array[i]);
  return 0;
}