#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

char infix[100], postfix[100];

typedef struct stack
{
  char *array, top;
} S;

S *create_stack()
{
  S *s = malloc(sizeof(S));
  s->array = malloc(MAX_STACK_SIZE * sizeof(char));
  s->top = -1;
}

void push(S *s, char ch)
{
  if (s->top == MAX_STACK_SIZE - 1)
  {
    printf("Stack overflow\n");
    return;
  }

  s->array[++s->top] = ch;
}

char pop(S *s)
{
  if (s->top == -1)
  {
    printf("Stack underflow\n");
    return '\0';
  }

  char popped = s->array[s->top];
  s->top--;
  return popped;
}

void free_stack(S *s)
{
  free(s->array);
  free(s);
}

int precedence(char ch)
{
  switch (ch)
  {
  case '^':
    return 3;
  case '*':
  case '/':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return 0;
  }
}

void get_postfix(char *infix)
{
  char next;
  int j = 0;
  S *s = create_stack();
  for (int i = 0; infix[i] != '\0'; i++)
  {
    if (infix[i] != ' ')
    {
      switch (infix[i])
      {
      case '(':
        push(s, infix[i]);
        break;
      case ')':
        while ((next = pop(s)) != '(')
          postfix[j++] = next;
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
        while (s->top != -1 && precedence(s->array[s->top]) >= precedence(infix[i]))
          postfix[j++] = pop(s);
        push(s, infix[i]);
        break;
      default:
        postfix[j++] = infix[i];
      }
    }
  }
  while (s->top != -1)
    postfix[j++] = pop(s);
  postfix[j] = '\0';
  free_stack(s);
}

int main()
{
  printf("Enter a valid infix expression:\n");
  fgets(infix, sizeof(infix), stdin);

  size_t len = strlen(infix);
  if (infix[len - 1] == '\n')
  {
    infix[len - 1] = '\0';
  }

  get_postfix(infix);

  printf("Postfix expression: ");
  for (int i = 0; postfix[i] != '\0'; i++)
    printf("%c", postfix[i]);
  printf("\n");

  return 0;
}