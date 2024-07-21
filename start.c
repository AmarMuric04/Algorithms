#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
  int id;
  char name[30];
} Student;

void println(const char *str)
{
  printf("%s\n", str);
}

void findPair(int arr[], size_t length, int first[], int second[])
{

  for (size_t i = 0; i < length - 1; ++i)
  {
    for (size_t j = i + 1; j < length; ++j)
    {
      if (arr[i] == arr[j])
      {
        first[0] = arr[i];
        second[0] = arr[j];
        first[1] = i;
        second[1] = j;
        return;
      }
    }
  }
}

Student *findStudent(int num, Student students[], int studentsLength)
{
  for (size_t i = 0; i < studentsLength; ++i)
  {
    if (num == students[i].id)
      return &students[i];
  }

  return NULL;
}

void sort(int arr[], int length)
{
  for (int i = 1; i < length; i++)
  {
    int j = i;
    while (j > 0 && arr[j] < arr[j - 1])
    {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
}
void nonDesctructiveSort(int arr[], int length, int toBeSorted[])
{
  for (int i = 0; i < length; i++)
    toBeSorted[i] = arr[i];

  for (int i = 1; i < length; i++)
  {
    int j = i;
    while (j > 0 && toBeSorted[j] < toBeSorted[j - 1])
    {
      int temp = toBeSorted[j];
      toBeSorted[j] = toBeSorted[j - 1];
      toBeSorted[j - 1] = temp;
      j--;
    }
  }
}

void printArray(int arr[], int length)
{
  for (size_t i = 0; i < length; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int list[] = {92, 5, 80, 39, 68, 56, 2, 77, 89, 16, 91, 53, 6, 40, 71, 15, 29,
                97, 41, 82, 54, 18, 67, 99, 24, 75, 64, 33, 42, 4, 71, 93, 61, 15, 83, 4, 57, 30, 21, 49, 74, 27, 81, 86, 24, 78, 39, 53, 99, 12, 6, 33, 55, 12, 28,
                14, 70, 45, 81, 22, 9, 27, 74, 31, 8, 99, 20, 53, 72, 40, 86, 11, 64, 23, 57,
                91, 8, 62, 43, 78, 49, 6, 85, 52, 27, 41, 63, 77, 3, 97, 50, 69, 12, 46, 58,
                30, 87, 42, 71, 22, 95, 59, 16, 85, 6, 64, 17, 48, 77, 20, 36, 72, 5, 81, 53,
                89, 23, 68, 19, 94, 2, 55, 34, 78, 43, 61, 10, 67, 26, 48, 90, 12, 73, 20, 84,
                46, 31, 61,
                14, 89, 2, 56, 7, 50, 34, 77, 65, 21, 84, 45, 18, 96, 62, 33, 12, 71, 46, 8,
                39, 77, 28, 90, 43, 64, 3, 53, 61, 26, 98, 11, 82, 39, 54, 70, 20, 88, 6, 40,
                81, 7, 45, 56, 13, 68, 99, 4, 94, 60, 48, 72, 19, 33, 29, 95, 88, 20, 63, 44,
                58, 11, 53, 77, 32, 66, 9, 97, 48, 79, 15, 91, 40, 21, 21, 73, 2, 90, 23, 47, 61, 88, 14, 39, 53, 15, 84, 16, 29, 35, 73, 22, 59, 98,
                72, 13, 64, 7, 47, 19, 51, 60,
                26, 85, 7, 19, 48, 59, 96, 63, 54, 28, 32, 87, 4, 60, 43, 71, 85, 22, 99, 5};
  size_t length = sizeof(list) / sizeof(list[0]);

  int first[2] = {-1, -1};
  int second[2] = {-1, -1};

  findPair(list, length, first, second);
  printf("%d (%d),%d (%d)\n", first[0], first[1], second[0], second[1]);

  Student amar = {0, "Amar Muric"};
  Student amarr = {40, "Amar2 Muric"};
  Student amarrr = {32, "Amar3 Muric"};
  Student amarrrr = {14, "Amar4 Muric"};
  Student amarrrrr = {72, "Amar5 Muric"};

  Student amari[5] = {amar, amarr, amarrr, amarrrr, amarrrrr};

  int korisnikovId;
  printf("ID trazenog studenta: ");
  scanf("%d", &korisnikovId);

  Student *foundAmar = findStudent(korisnikovId, amari, 5);

  if (foundAmar)
    printf("Ime studenta sa datim identifikacionim brojem je: %s", foundAmar->name);
  else
    printf("Ne postoji student sa datim identifikacionim brojem...");

  // sort(list, length);

  // int sortedList[length];
  // nonDesctructiveSort(list, length, sortedList);

  // printArray(sortedList, length);
  // printArray(list, length);
  // println("YOO");
  return 0;
}