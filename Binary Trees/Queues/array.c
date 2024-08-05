#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *create_node(int data)
{
  Node *n = malloc(sizeof(Node));
  n->left = n->right = NULL;
  n->data = data;

  return n;
}

typedef struct queue
{
  Node **array;
  int front, rear, size;
  unsigned capacity;
} Queue;

Queue *create_queue(unsigned capacity)
{
  Queue *s = (Queue *)malloc(sizeof(Queue));
  s->capacity = capacity;
  s->front = s->rear = 0;
  s->size = 0;
  s->array = (Node **)malloc(capacity * sizeof(Node *));

  return s;
}

bool is_empty(Queue *s)
{
  return s->size == 0;
}

bool is_full(Queue *s)
{
  return s->size == s->capacity;
}

void enqueue(Queue *s, Node *n)
{

  if (is_full(s))
  {
    printf("Queue overflow\n");
    return;
  }
  s->array[s->rear] = n;
  s->rear = (s->rear + 1) % s->capacity;
  s->size++;
}

Node *dequeue(Queue *s)
{
  if (is_empty(s))
  {
    printf("Queue underflow\n");
    return NULL;
  }
  Node *popped = s->array[s->front];
  s->front = (s->front + 1) % s->capacity;
  s->size--;
  return popped;
}

void insert_to_bt(Node **root, int data)
{
  Node *n = create_node(data);
  if (*root == NULL)
  {
    *root = n;
    return;
  }

  Queue *q = create_queue(100);
  enqueue(q, *root);

  while (q->front < q->rear)
  {
    Node *current = dequeue(q);

    if (current->left == NULL)
    {
      current->left = n;
      break;
    }
    else
      enqueue(q, current->left);

    if (current->right == NULL)
    {
      current->right = n;
      break;
    }
    else
      enqueue(q, current->right);
  }
  free(q->array);
  free(q);
}

void insert_to_bst(Node **root, int data)
{
  Node *n = create_node(data);

  if (*root == NULL)
  {
    *root = n;
    return;
  }

  Queue *q = create_queue(100);
  enqueue(q, *root);

  while (!is_empty(q))
  {
    Node *t = dequeue(q);
    // -------
    if (data < t->data)
    {
      if (t->left == NULL)
      {
        t->left = n;
        break;
      }
      else
        enqueue(q, t->left);
    }
    // -------
    else
    {
      if (t->right == NULL)
      {
        t->right = n;
        break;
      }
      else
        enqueue(q, t->right);
    }
  }
}

void print_queue(Node *root)
{

  if (root == NULL)
  {
    return;
  }

  Queue *q = create_queue(100);
  enqueue(q, root);

  while (!is_empty(q))
  {
    Node *t = dequeue(q);
    printf("%d ", t->data);
    // -------
    if (t->left != NULL)
      enqueue(q, t->left);
    if (t->right != NULL)
      enqueue(q, t->right);
  }
  // -------
}

void free_queue(Queue *q)
{
  free(q->array);
  free(q);
}

// void inorder(Node *root)
// {
//   if (root != NULL)
//   {
//     inorder(root->left);
//     printf("%d ", root->data);
//     inorder(root->right);
//   }
// }

int main()
{
  // Node *root = NULL;
  // insert_to_bt(&root, 100);
  // insert_to_bt(&root, 200);
  // insert_to_bt(&root, 300);
  // insert_to_bt(&root, 400);
  // insert_to_bt(&root, 500);
  // insert_to_bt(&root, 600);
  // insert_to_bt(&root, 700);

  // inorder(root);

  Node *root = NULL;
  insert_to_bst(&root, 100);
  insert_to_bst(&root, 200);
  insert_to_bst(&root, 300);
  insert_to_bst(&root, 400);
  insert_to_bst(&root, 500);
  insert_to_bst(&root, 600);
  insert_to_bst(&root, 700);

  print_queue(root);
  return 0;
}