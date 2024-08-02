#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

Node *create_node(int data)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->right = new_node->left = NULL;
  return new_node;
}

Node *insert_helper(Node *root, Node *node)
{
  if (root == NULL)
  {
    printf("Inserting a new node!\n");
    return node;
  }
  if (node->data > root->data)
    root->right = insert_helper(root->right, node);
  else if (node->data < root->data)
    root->left = insert_helper(root->left, node);

  return root;
}

void insert(Node **root, Node *node)
{
  *root = insert_helper(*root, node);
}

void in_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  in_order(root->left);
  printf("%d\n", root->data);
  in_order(root->right);
}

void pre_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  printf("%d\n", root->data);
  in_order(root->left);
  in_order(root->right);
}

void post_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  in_order(root->left);
  in_order(root->right);
  printf("%d\n", root->data);
}

void print_in_order(Node *root)
{
  in_order(root);
}

void print_pre_order(Node *root)
{
  pre_order(root);
}

void print_post_order(Node *root)
{
  post_order(root);
}

int main()
{
  Node *root = NULL;
  Node *n1 = create_node(100);
  Node *n2 = create_node(50);
  Node *n3 = create_node(200);
  Node *n4 = create_node(150);
  Node *n5 = create_node(40);

  insert(&root, n1);
  insert(&root, n2);
  insert(&root, n3);
  insert(&root, n4);
  insert(&root, n5);

  print_in_order(root);
  printf("-----\n");
  print_pre_order(root);
  printf("-----\n");
  print_post_order(root);
  return 0;
}