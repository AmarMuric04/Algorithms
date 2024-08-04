#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

typedef struct StackNode
{
  TreeNode *treeNode;
  struct StackNode *next;
} StackNode;

TreeNode *newTreeNode(int data)
{
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

StackNode *newStackNode(TreeNode *treeNode)
{
  StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
  stackNode->treeNode = treeNode;
  stackNode->next = NULL;
  return stackNode;
}

void push(StackNode **top, TreeNode *treeNode)
{
  StackNode *stackNode = newStackNode(treeNode);
  stackNode->next = *top;
  *top = stackNode;
}

TreeNode *pop(StackNode **top)
{
  if (*top == NULL)
    return NULL;
  StackNode *temp = *top;
  *top = (*top)->next;
  TreeNode *treeNode = temp->treeNode;
  free(temp);
  return treeNode;
}

int isEmpty(StackNode *top)
{
  return top == NULL;
}

void inorderTraversal(TreeNode *root)
{
  StackNode *stack = NULL; 
  TreeNode *current = root;

  while (current != NULL || !isEmpty(stack))
  {
    while (current != NULL)
    {
      push(&stack, current);
      current = current->left;
    }

    current = pop(&stack);
    printf("%d ", current->data);

    current = current->right;
  }
}

int main()
{
  TreeNode *root = newTreeNode(1);
  root->left = newTreeNode(2);
  root->right = newTreeNode(3);
  root->left->left = newTreeNode(4);
  root->left->right = newTreeNode(5);

  printf("In-order Traversal: ");
  inorderTraversal(root);

  return 0;
}
