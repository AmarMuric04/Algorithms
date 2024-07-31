#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 10000

int top = -1;
int stack[MAX];
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

bool check_brackets()
{
  for (size_t i = 0; infix[i] != '\0'; ++i)
  {
    if (infix[i] == '(')
      push(infix[i]);
    else if (infix[i] == ')')
    {
      if (isEmpty())
      {
        printf("There's too many right brackets.\n");
        return false;
      }
      if (pop() != '(')
      {
        printf("Mismatching brackets.\n");
        return false;
      }
    }
  }
  if (!isEmpty())
  {
    printf("There's too many left brackets.\n");
    return false;
  }
  printf("%d", top);
  return true;
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

int postfix_evaluated()
{
  int a, b;
  for (size_t i = 0; postfix[i] != '\0'; ++i)
  {
    if (isdigit(postfix[i]))
    {
      push(postfix[i] - '0');
    }
    else
    {
      a = pop();
      b = pop();

      switch (postfix[i])
      {
      case '+':
        push(b + a);
        break;
      case '-':
        push(b - a);
        break;
      case '*':
        push(b * a);
        break;
      case '/':
        if (a == 0)
        {
          printf("Error: Division by zero.\n");
          return 0;
        }
        push(b / a);
        break;
      case '^':
        push((int)round(pow(b, a)));
        break;
      default:
        printf("Error: Unsupported operator '%c'.\n", postfix[i]);
        return 0;
      }
    }
  }
  return pop();
}

int main()
{
  printf("Enter the infix expression: ");
  fgets(infix, sizeof(infix), stdin);
  int result;

  check_brackets();
  turn_to_postfix(infix);
  result = postfix_evaluated();

  print();
  printf("Final result is: %d", result);
  return 0;
}