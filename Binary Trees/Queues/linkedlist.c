#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int data;
  struct node *left, *right;
} Node;

Node *create_node(int data)
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->left = NULL;
  n->right = NULL;
  n->data = data;

  return n;
}

typedef struct queueNode
{
  Node *treeNode;
  struct queueNode *next;
} QueueNode;

typedef struct queue
{
  QueueNode *front, *rear;
} Queue;

void enqueue(Queue *queue, Node *node)
{
  QueueNode *qn = (QueueNode *)malloc(sizeof(QueueNode));
  qn->treeNode = node;
  qn->next = NULL;
  if (queue->rear == NULL)
  {
    queue->rear = queue->front = qn;
    return;
  }

  queue->rear->next = qn;
  queue->rear = qn;
}

Queue *create_queue()
{
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q->front = q->rear = NULL;

  return q;
}

Node *dequeue(Queue *queue)
{
  if (queue->front == NULL)
  {
    printf("Queue underflow\n");
    return NULL;
  }
  QueueNode *qn = queue->front;
  queue->front = queue->front->next;
  if (queue->front == NULL)
  {
    queue->rear = NULL;
  }
  Node *n = qn->treeNode;
  free(qn);
  return n;
}

bool is_empty(Queue *q)
{
  return q->front == NULL;
}

void insert(Node **root, int data)
{
  Node *n = create_node(data);
  if (*root == NULL)
  {
    *root = n;
    return;
  }
  Queue *q = create_queue();
  enqueue(q, *root);
  while (!is_empty(q))
  {
    Node *temp = dequeue(q);
    if (temp->left == NULL)
    {
      temp->left = n;
      break;
    }
    else
      enqueue(q, temp->left);
    if (temp->right == NULL)
    {
      temp->right = n;
      break;
    }
    else
      enqueue(q, temp->right);
  }
}

void bst_insert(Node **root, int data)
{
  Node *n = create_node(data);

  if (*root == NULL)
  {
    *root = n;
    return;
  }

  Queue *q = create_queue();
  enqueue(q, *root);

  while (!is_empty(q))
  {
    Node *temp = dequeue(q);

    if (data < temp->data)
    {
      if (temp->left == NULL)
      {
        temp->left = n;
        break;
      }
      else
        enqueue(q, temp->left);
    }
    else
    {
      if (temp->right == NULL)
      {
        temp->right = n;
        break;
      }
      else
        enqueue(q, temp->right);
    }
  }
  free(q);
}

void inorder(Node *root)
{

  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void postorder(Node *root)
{

  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

void preorder(Node *root)
{

  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main()
{
  Node *root = create_node(10);

  bst_insert(&root, 305);
  bst_insert(&root, 205);
  bst_insert(&root, 405);
  bst_insert(&root, 1005);
  bst_insert(&root, 605);
  bst_insert(&root, 105);
  bst_insert(&root, 805);
  bst_insert(&root, 705);
  bst_insert(&root, 1305);
  bst_insert(&root, 1105);
  bst_insert(&root, 905);
  bst_insert(&root, 1205);
  inorder(root);
  printf("\n");
  preorder(root);
  printf("\n");
  postorder(root);
  return 0;
}

// using bst_insert helps inorder print items in a sorted non-descending manner.
// insert(&root, 105);
// insert(&root, 205);
// insert(&root, 305);
// insert(&root, 405);
// insert(&root, 605);
// insert(&root, 705);
// insert(&root, 805);
// insert(&root, 905);
// insert(&root, 1005);
// insert(&root, 1105);
// insert(&root, 1205);
// insert(&root, 1305);