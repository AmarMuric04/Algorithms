void add(Node *node, int num)
{
  if (num == 0)
  {
    return;
  }

  if (node == NULL || node->left == NULL && node->right == NULL)
    return;
  Node *stack[100]; 
  int top = -1;

  stack[++top] = node;

  while (top != -1)
  {
    Node *current = stack[top--];

    current->data += num;

    if (current->left != NULL)
    {
      stack[++top] = current->left;
    }
    if (current->right != NULL)
    {
      stack[++top] = current->right;
    }
  }
}