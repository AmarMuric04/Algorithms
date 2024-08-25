#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct node
{
  int val;
  struct node *left, *right;
} Node;

typedef struct queue_node
{
  Node *treeNode;
  struct queue_node *next;
} QueueNode;

typedef struct queue
{
  QueueNode *front;
  QueueNode *rear;
} Queue;

Queue *init_queue()
{
  Queue *q = malloc(sizeof(Queue));
  q->front = q->rear = NULL;

  return q;
}

void enqueue(Queue *q, Node *treeNode)
{
  QueueNode *qn = malloc(sizeof(QueueNode));
  qn->next = NULL;
  qn->treeNode = treeNode;

  if (q->rear == NULL)
  {
    q->front = q->rear = qn;
  }
  else
  {
    q->rear->next = qn;
    q->rear = qn;
  }
}

Node *dequeue(Queue *q)
{
  if (q->front == NULL)
    return NULL;
  QueueNode *temp = q->front;
  Node *treeNode = temp->treeNode;
  q->front = temp->next;
  if (q->front == NULL)
    q->rear = NULL;
  free(temp);
  return treeNode;
}

Node *init_node(int value)
{
  Node *n = malloc(sizeof(Node));
  n->left = n->right = NULL;
  n->val = value;

  return n;
}

bool is_empty(Queue *q)
{
  return q->front == NULL;
}

void insert_to_tree(Node **root, int value)
{
  Node *n = init_node(value);

  if (*root == NULL)
  {
    *root = n;
    return;
  }

  Queue *q = init_queue();
  enqueue(q, *root);

  while (true)
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
}

int check_if_same(Node *root1, Node *root2)
{
  if (root1 == NULL && root2 == NULL)
    return 1;
  if (root1 == NULL || root2 == NULL)
    return 0;
  if (root1->val != root2->val)
    return 0;

  return check_if_same(root1->left, root2->left) &&
         check_if_same(root1->right, root2->right);
}

void print_tree(Node *root)
{
  if (root == NULL)
    return;

  print_tree(root->left);
  printf("%d, ", root->val);
  print_tree(root->right);
}

int main()
{
  Node *root1 = NULL;
  Node *root2 = NULL;

  insert_to_tree(&root1, 1);
  insert_to_tree(&root1, 2);
  insert_to_tree(&root1, 3);
  insert_to_tree(&root1, 4);
  insert_to_tree(&root1, 5);
  insert_to_tree(&root1, 6);

  print_tree(root1);
  printf("->%d<-", check_if_same(root1, root2));
  printf("\n");

  return 0;
}