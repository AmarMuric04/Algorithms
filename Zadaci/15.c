#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *left, *right;
} Node;

Node *init_node(int value)
{
  Node *n = malloc(sizeof(Node));
  n->right = n->left = NULL;
  n->value = value;

  return n;
}

Node *insert_to_tree(Node *root, int value)
{

  if (root == NULL)
  {
    return init_node(value);
  }

  if (value < root->value)
  {
    root->left = insert_to_tree(root->left, value);
  }
  else if (value > root->value)
  {
    root->right = insert_to_tree(root->right, value);
  }

  return root;
}

void print(Node *root)
{
  if (root == NULL)
    return;

  if (root->left == NULL && root->right == NULL)
    printf("%d ", root->value);

  print(root->left);
  print(root->right);
}

int main()
{

  Node *root = NULL; 

  root = insert_to_tree(root, 10);
  insert_to_tree(root, 50);
  insert_to_tree(root, 200);
  insert_to_tree(root, 400);
  insert_to_tree(root, 80);
  insert_to_tree(root, 900);
  insert_to_tree(root, 0);

  print(root);

  return 0;
}