// Program to print binary tree in 2D
#include <stdio.h>
#include <malloc.h>
#define COUNT 10

// A binary tree node
struct Node
{
  int data;
  struct Node *left, *right;
};

// Helper function to allocates a new node
struct Node *newNode(int data)
{
  struct Node *node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node *root, int space)
{
  // Base case
  if (root == NULL)
    return;

  // Increase distance between levels
  space += COUNT;

  // Process right child first
  print2DUtil(root->right, space);

  // Print current node after space
  // count
  printf("\n");
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root->data);

  // Process left child
  print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
  // Pass initial space count as 0
  print2DUtil(root, 0);
}

void exibirArvore2(struct Node *raiz, int level)
{
  if (raiz != NULL)
  {
    printf("    %c\n", raiz->data);
    if (raiz->left != NULL && raiz->right != NULL)
    {
      putchar('+');
      for (int i = 0; i < (4 * 2); i++)
      {
        putchar('-');
      }
      putchar('+');
      printf("\n");
    }
    exibirArvore(raiz->left, level + 1);
    exibirArvore(raiz->right, level + 1);
  }
}

void padding(char ch, int n)
{
  for (int i = 0; i < n; i++)
    putchar(ch);
}

void structure(struct Node *root, int level)
{
  if (root == NULL)
  {
    padding('\t', level);
    puts("");
  }
  else
  {
    structure(root->right, level + 1);
    padding('\t', level);
    printf("%d\n", root->data);
    structure(root->left, level + 1);
  }
}

// Driver program to test above functions
int main()
{
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);

  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);

  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(11);
  root->right->left->left = newNode(12);
  root->right->left->right = newNode(13);
  root->right->right->left = newNode(14);
  root->right->right->right = newNode(15);

  //print2D(root);
  structure(root, 0);

  return 0;
}

/* Função que encontra o primeiro operador, aquele q será a raiz da arvore */
int raizIndex(char *expressao, int ini, int fim)
{
  printf("$ %d %d\n", ini, fim);
  int index = -1;

  if (ini == fim)
  {
    if (!ehOperador(expressao[ini]))
      return ini;
    else
      return -1;
  }

  if (expressao[0] == '(')
  { /* Caso a expressão comece com um parênteses */
    int parenteseOpen = 1;
    for (int i = ini + 1; i < fim; i++)
    {
      if (expressao[i] == '(')
      {
        parenteseOpen = 1;
      }
      else if (expressao[i] == ')')
      {
        parenteseOpen = 0;
      }
      else if (ehOperador(expressao[i]) && !parenteseOpen)
      {
        index = i;
      }
    }
  }
  else
  { /* Caso a expressão não comece com um parênteses */
    for (int i = ini; i < fim; i++)
    {
      if (ehOperador(expressao[i]))
      {
        index = i;
        break;
      }
    }
  }                                                       /* Até aqui, index é o primeiro operador encontrado */
  if (expressao[index] == '*' || expressao[index] == '/') /* Respeitando  a precedência dos operadores */
    index = raizIndex(expressao, index + 1, fim);

  return index;
}