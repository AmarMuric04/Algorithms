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
  array[hash_function(number)] = number;
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

  int values[] = {18, 41, 22, 44, 59, 32, 31, 73};
  int num_values = sizeof(values) / sizeof(values[0]);

  for (int i = 0; i < num_values; i++)
  {
    hash_insert(array, values[i]);
  }
  print_hash(array);

  return 0;
}