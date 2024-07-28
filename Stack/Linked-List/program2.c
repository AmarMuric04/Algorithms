#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define WORD_MAX 50

struct node
{
  char data;
  struct node *next;
};

bool is_empty(struct node *top)
{
  return top == NULL;
}

void push_to_llstack(struct node **top, char data)
{
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  if (new_node == NULL)
  {
    printf("Stack overflow.\n");
    exit(1);
  }
  new_node->next = *top;
  new_node->data = data;
  *top = new_node;
}

char pop_from_llstack(struct node **top)
{
  if (is_empty(*top))
  {
    printf("Stack underflow.\n");
    exit(1);
  }

  struct node *temp = *top;
  char value = temp->data;

  *top = (*top)->next;
  free(temp);

  return value;
}

void print_llstack(struct node *top)
{
  if (is_empty(top))
  {
    printf("Can't print, llstack is empty.\n");
    return;
  }
  struct node *current = top;

  while (current != NULL)
  {
    printf("%c", current->data);
    if (current->next != NULL)
      printf(" - ");
    current = current->next;
  }
  printf("\n");
}

bool is_palindrome(char word[])
{
  struct node *stack = NULL;
  int word_length = strlen(word) - 1;
  int middle = word_length / 2;
  size_t index = 0;

  if (word_length % 2 == 0)
    middle--;

  while (index < middle)
  {
    push_to_llstack(&stack, word[index]);
    index++;
  }

  if (word_length % 2 == 0)
    index++;

  index++;

  while (index < word_length)
  {
    char stack_char = pop_from_llstack(&stack);
    if (word[index] != stack_char)
    {
      while (stack != NULL)
      {
        pop_from_llstack(&stack);
      }
      return false;
    }
    index++;
  }
  while (stack != NULL)
  {
    pop_from_llstack(&stack);
  }

  return true;
}

int main()
{
  char word[WORD_MAX];
  fgets(word, sizeof(word), stdin);

  if (is_palindrome(word))
    printf("palindrome!");
  else
    printf("not a palindrome");

  return 0;
}
