#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

int top = -1;
char stack[MAX];
char infix[MAX], postfix[MAX];

void print()
{
  size_t i = 0;
  printf("The equivalent postfix expression is: ");
  while (postfix[i])
    printf("%c", postfix[i++]);
  printf("\n");
}

bool isEmpty()
{
  return top == -1;
}

bool isFull()
{
  return top == MAX - 1;
}

bool isSpace(char symbol)
{
  return symbol == ' ' || symbol == '\t' || symbol == '\n';
}

void push(char symbol)
{
  if (isFull())
  {
    printf("Stack overflow.\n");
    return;
  }

  top++;
  stack[top] = symbol;
}

char pop()
{
  if (isEmpty())
  {
    printf("Stack underflow.\n");
    return '\0';
  }

  return stack[top--];
}

int precedence(char symbol)
{
  switch (symbol)
  {
  case '^':
    return 3;
  case '/':
  case '*':
    return 2;
  case '+':
  case '-':
    return 1;
  default:
    return 0;
  }
}

void turn_to_postfix()
{
  char symbol, next;
  size_t j = 0;
  for (size_t i = 0; infix[i] != '\0'; ++i)
  {
    symbol = infix[i];

    if (!isSpace(symbol))
    {
      switch (symbol)
      {
      case '(':
        push(symbol);
        break;
      case ')':
        while ((next = pop()) != '(')
          postfix[j++] = next;
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
        while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
          postfix[j++] = pop();
        push(symbol);
        break;
      default:
        postfix[j++] = symbol;
      }
    }
  }
  while (!isEmpty())
    postfix[j++] = pop();
  postfix[j] = '\0';
}

int main()
{
  printf("Enter the infix expression: ");
  fgets(infix, sizeof(infix), stdin);

  turn_to_postfix(infix);

  print();
  return 0;
}