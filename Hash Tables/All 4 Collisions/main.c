#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define HASH_SIZE 15
#define EMPTY INT_MIN

typedef struct hash
{
  int *array, size;
  unsigned capacity;
} Hash;

typedef struct node
{
  int data;
  struct node *next;
} Node;

typedef struct chaining_hash
{
  struct node **array;
  int capacity;
} cHash;

Node *create_node(int data)
{
  Node *n = malloc(sizeof(Node));
  n->data = data;
  n->next = NULL;

  return n;
}

cHash *init_chaining_hash()
{
  cHash *chash = malloc(sizeof(cHash));
  chash->capacity = HASH_SIZE;
  chash->array = malloc(HASH_SIZE * sizeof(struct node *));

  for (int i = 0; i < HASH_SIZE; i++)
  {
    chash->array[i] = NULL;
  }

  return chash;
}

bool is_full(Hash *h)
{

  for (int i = 0; i < HASH_SIZE; i++)
    if (h->array[i] == EMPTY)
      return false;
  return true;
}

Hash *init_hash()
{
  Hash *h = malloc(sizeof(Hash));
  h->capacity = HASH_SIZE;
  h->array = malloc(HASH_SIZE * sizeof(int));
  for (int i = 0; i < HASH_SIZE; i++)
    h->array[i] = EMPTY;

  return h;
}

int hash(int data)
{
  return data % HASH_SIZE;
}

// for double hashing
int hash_2(int data)
{
  return 7 - (data % 7);
}

// double hashing
void insert_double_hashing(Hash *h, int data)
{
  if (is_full(h))
  {
    printf("Hash table is full.\n");
    return;
  }

  int index = hash(data);
  int stepSize = hash_2(data);

  while (h->array[index] != EMPTY)
    index = (index + stepSize) % HASH_SIZE;
  h->array[index] = data;
}

// linear probing
void insert_linear_probing(Hash *h, int data)
{
  int index = hash(data);
  int jndex = index;
  while (h->array[jndex] != EMPTY)
  {
    jndex = (jndex + 1) % HASH_SIZE;
    if (jndex == index)
    {
      printf("Hash table is full.\n");
      return;
    };
  }
  h->array[jndex] = data;
}

// quadratic
void insert_quadratic(Hash *h, int data)
{
  if (is_full(h))
  {
    printf("Hash table is full.\n");
    return;
  }

  int index = hash(data);
  int i = 1;
  while (h->array[index] != EMPTY)
  {
    index = (index + i * i) % HASH_SIZE;
    i++;
  }
  h->array[index] = data;
}

// closed addressing -> chaining
void insert_chaining(cHash *h, int data)
{
  int index = hash(data);
  Node *current = h->array[index];

  if (current == NULL)
  {
    h->array[index] = create_node(data);
    return;
  }

  while (current->next != NULL)
    current = current->next;

  current->next = create_node(data);
}

void print_hash(Hash *h)
{
  for (int i = 0; i < HASH_SIZE; i++)
    printf("%d ", h->array[i]);

  printf("\n");
}

void print_chaining_hash(cHash *h)
{
  for (int i = 0; i < HASH_SIZE; i++)
  {
    printf("[%d]: ", i);
    Node *current = h->array[i];
    while (current != NULL)
    {
      printf("%d -> ", current->data);
      current = current->next;
    }
    printf("NULL\n");
  }
}

void free_chaining_hash(cHash *h)
{
  for (int i = 0; i < HASH_SIZE; i++)
  {
    Node *current = h->array[i];
    while (current != NULL)
    {
      Node *temp = current;
      current = current->next;
      free(temp);
    }
  }
  free(h->array);
  free(h);
}

int main()
{
  int array[15] = {1, 16, 31, 2, 17, 32, 3, 18, 33, 4, 19, 34, 5, 20, 35};
  int length = sizeof(array) / sizeof(array[0]);

  Hash *h = init_hash();
  cHash *ch = init_chaining_hash();
  for (int i = 0; i < length; i++)
    insert_chaining(ch, array[i]);
  // print_hash(h);
  print_chaining_hash(ch);

  free_chaining_hash(ch);

  return 0;
}