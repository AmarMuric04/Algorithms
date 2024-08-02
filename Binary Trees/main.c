#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

int successor(Node *root)
{
  while (root->right != NULL)
  {
    root = root->right;
  }

  return root->data;
}

int predecessor(Node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }

  return root->data;
}

Node *create_node(int data)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->data = data;
  return new_node;
}

Node *insert_helper(Node *root, Node *node)
{
  if (root == NULL)
  {
    printf("Inserted as a new node.\n");
    return node;
  }
  else if (root->data == node->data)
  {
    printf("Already in BST.\n");
  }
  else if (root->data > node->data)
  {
    root->left = insert_helper(root->left, node);
  }
  else if (root->data < node->data)
  {
    root->right = insert_helper(root->right, node);
  }

  return root;
}

void insert(Node **root, Node *node)
{
  *root = insert_helper(*root, node);
}

void print_tabs(int tabs)
{
  for (int i = 0; i < tabs; i++)
    printf("  ");
}

void print_helper(Node *root, int tabs)
{
  if (root == NULL)
  {
    print_tabs(tabs);
    printf("-<empty>-\n");
    return;
  }
  print_tabs(tabs);
  printf("left: \n");
  print_helper(root->left, tabs + 2);

  print_tabs(tabs);
  printf("%d\n", root->data);

  print_tabs(tabs);
  printf("right: \n");
  print_helper(root->right, tabs + 2);
}

void print(Node *root)
{
  print_helper(root, 0);
}

Node *delete_helper(Node *root, int data)
{
  if (root == NULL)
  {
    printf("The BST is empty.\n");
    return NULL;
  }
  if (root->data > data)
    root->left = delete_helper(root->left, data);
  if (root->data < data)
    root->right = delete_helper(root->right, data);
  else
  {
    if (root->left == NULL && root->right == NULL)
      root = NULL;
    else if (root->right != NULL)
    {
      root->data = successor(root);
      root->right = delete_helper(root->right, data);
    }
    else if (root->left != NULL)
    {
      root->data = predecessor(root);
      root->left = delete_helper(root->left, data);
    }
  }
  return root;
}

void delete(Node **root, int data)
{
  delete_helper(*root, data);
}

int main()
{
  Node *root = NULL;

  Node *new_node = create_node(1);
  insert(&root, new_node);
  Node *new_node1 = create_node(5);
  insert(&root, new_node1);
  Node *new_node2 = create_node(3);
  insert(&root, new_node2);
  Node *new_node3 = create_node(8);
  insert(&root, new_node3);
  Node *new_node4 = create_node(7);
  insert(&root, new_node4);
  Node *new_node5 = create_node(2);
  insert(&root, new_node5);
  Node *new_node6 = create_node(9);
  insert(&root, new_node6);
  Node *new_node7 = create_node(6);
  insert(&root, new_node7);
  print(root);

  delete (&root, 8);
  print(root);

  return 0;
}
