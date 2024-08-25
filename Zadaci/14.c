#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define EMPTY INT_MIN

typedef struct hash
{
  int *array, capacity;
} Hash;

Hash *init_hash(int capacity)
{
  Hash *h = malloc(sizeof(Hash));
  h->array = malloc(sizeof(int) * capacity);
  h->capacity = capacity;

  for (int i = 0; i < h->capacity; i++)
    h->array[i] = EMPTY;

  return h;
}

int hash_f(Hash *h, int key)
{
  return key % h->capacity;
}

void insert(Hash *h, int key, int value)
{
  int index = hash_f(h, key);
  int jndex = index;
  while (h->array[jndex] != EMPTY)
  {
    jndex = (jndex + 1) % h->capacity;
    if (jndex == index)
    {
      printf("Hash table is full.\n");
      return;
    };
  }
  h->array[jndex] = value;
}

void print_hash(Hash *h)
{
  for (int i = 0; i < h->capacity; i++)
  {
    if (h->array[i] != EMPTY)
    {
      printf("Index %d: %d\n", i, h->array[i]);
    }
    else
    {
      printf("Index %d: EMPTY\n", i);
    }
  }
}

void free_hash(Hash *h)
{
  free(h->array);
  free(h);
}
int main()
{
  Hash *h = init_hash(10);
  insert(h, 5, 20);
  insert(h, 15, 25);
  insert(h, 25, 30);
  insert(h, 35, 35);
  insert(h, 15, 25);
  insert(h, 15, 25);
  insert(h, 15, 25);
  insert(h, 15, 25);
  insert(h, 15, 25);
  insert(h, 15, 25);

  print_hash(h);

  free_hash(h);

  return 0;
}