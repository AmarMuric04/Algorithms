#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool match_brackets(char left, char right)
{
  return (left == '[' && right == ']') ||
         (left == '(' && right == ')') ||
         (left == '{' && right == '}');
}

bool good_brackets(char string[])
{
  struct node *left_brackets = NULL;

  int string_length = strlen(string);
  size_t index = 0;

  while (index < string_length)
  {
    if (string[index] == '[' || string[index] == '(' || string[index] == '{')
      push_to_llstack(&left_brackets, string[index]);
    else if (string[index] == ']' || string[index] == ')' || string[index] == '}')
    {
      if (is_empty(left_brackets))
      {
        printf("There's more right brackets.\n");
        return false;
      }

      if (!match_brackets(pop_from_llstack(&left_brackets), string[index]))
      {
        printf("Mismatched brackets.\n");
        return false;
      }
    }
    index++;
  }
  if (is_empty(left_brackets))
  {
    printf("Expression is fine.\n");
    return true;
  }
  else
  {
    printf("There are unmatched left brackets.\n");
    print_llstack(left_brackets);
    return false;
  }
}

int main()
{
  char expression[200] = "(A + B) - { 4 * 8 } / [ 36 - 48 ]";

  good_brackets(expression);

  return 0;
}
