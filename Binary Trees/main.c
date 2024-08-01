#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int data;
  struct node *left;
  struct node *right;
} Node;

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

int main()
{
  Node *root = NULL;

  for (int i = 0; i < 10; i++)
  {
    int data = rand() % 1000;
    Node *new_node = create_node(data);
    insert(&root, new_node);
  }

  print(root);

  return 0;
}
