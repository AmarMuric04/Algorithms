#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node

{
  int value;
  struct node *left, *right;
} Node;

Node *init_node(int value)
{
  Node *n = malloc(sizeof(Node));
  n->left = n->right = NULL;
  n->value = value;

  return n;
}

Node *insert(Node *root, int value)
{
  if (root == NULL)
    return init_node(value);

  if (value < root->value)
    root->left = insert(root->left, value);
  else if (value > root->value)
    root->right = insert(root->right, value);

  return root;
}

typedef struct
{
  Node *data[100];
  int front, rear;
} Queue;

/*traversing with queue*/

void enqueue(Queue *q, Node *value)
{
  q->data[q->rear++] = value;
}

Node *dequeue(Queue *q)
{
  return q->data[q->front++];
}

bool is_empty(Queue *q)
{
  return q->rear == q->front;
}

void print_it(Node *root)
{
  Queue *q = malloc(sizeof(Queue));
  q->front = q->rear = 0;

  enqueue(q, root);
  while (!is_empty(q))
  {
    Node *n = dequeue(q);
    printf("%d ", n->value);
    if (n->left != NULL)
      enqueue(q, n->left);
    if (n->right != NULL)
      enqueue(q, n->right);
  }
  free(q);
}

typedef struct
{
  Node *data[100];
  int top;
} Stack;

bool is_empty_stack(Stack *s)
{
  return s->top == -1;
}

void push(Stack *s, Node *node)
{
  s->data[++s->top] = node;
}

Node *pop(Stack *s)
{
  return s->data[s->top--];
}

void in_order(Node *root)
{
  Stack *s = malloc(sizeof(Stack));
  s->top = -1;
  Node *current = root;

  while (current != NULL || !is_empty_stack(s))
  {
    while (current != NULL)
    {
      push(s, current);
      current = current->left;
    }

    current = pop(s);
    printf("%d ", current->value);
    current = current->right;
  }
}

void pre_order(Node *root)
{
  Stack *s = malloc(sizeof(Stack));
  s->top = -1;

  push(s, root);
  while (!is_empty_stack(s))
  {
    Node *current = pop(s);
    printf("%d ", current->value);
    if (current->left)
      push(s, current->left);
    if (current->right)
      push(s, current->right);
  }
}

void post_order(Node *root)
{
  Stack *s1 = malloc(sizeof(Stack));
  Stack *s2 = malloc(sizeof(Stack));
  s1->top = s2->top = -1;

  push(s1, root);
  while (!is_empty_stack(s1))
  {
    Node *current = pop(s1);
    push(s2, current);

    if (current->left)
      push(s1, current->left);
    if (current->right)
      push(s1, current->right);
  }

  while (!is_empty_stack(s2))
  {
    Node *current = pop(s2);
    printf("%d ", current->value);
  }

  free(s1);
  free(s2);
}

int main()
{
  Node *root = NULL;
  root = insert(root, 100);
  insert(root, 40);
  insert(root, 50);
  insert(root, 200);
  insert(root, 90);
  insert(root, 300);

  in_order(root);
  printf("\n");
  pre_order(root);
  printf("\n");
  post_order(root);

  return 0;
}