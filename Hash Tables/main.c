#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define TABLE_SIZE 17

int hash_function(int number)
{
  return number % TABLE_SIZE;
}

int hash_insert(int *array, int number)
{
  int index = hash_function(number);
  if (array[index] != INT_MIN)
  {
    printf("Collision -> %d\n", number);
    return INT_MIN;
  }

  array[index] = number;
}

void print_hash(int *array)
{
  for (int i = 0; i < TABLE_SIZE; i++)
    printf("%d\n", array[i]);
}

int main()
{
  int array[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; i++)
    array[i] = INT_MIN;

  int values[] = {18, 41, 22, 44, 59, 32, 31, 73, 48, 39, 15, 14, 16, 17, 13, 12, 11, 9, 6, 4, 3, 2};
  int num_values = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < num_values; i++)
  {
    hash_insert(array, values[i]);
  }
  print_hash(array);

  return 0;
}