// Atividade 08,Álgebra Linear

struct node 
{
  int key;
  node * left;
  node * right;
};

struct node * newNode(int key)
{
  struct node * node = new struct node;
  node->key = key;
  node->left = nullptr;
  node->right = nullptr;

  return node;
}

struct node * arrayToTree(node * root, int key)
{
  if (root == nullptr)
  {
    return newNode(key);
  }
  
  if (key >= root->key)
    root->right = arrayToTree(root->right, key);

  else if (key < root->key)
    root->left = arrayToTree(root->left, key);

  return root;
}

node * loadTree(int * u, int n) 
{
    /*
monta árvore a partir  
   da inseção consecutiva de chaves do vetor u.  
*/
  struct node * root = nullptr;

  for (int i = 0; i < n; i++)
    root = arrayToTree(root, u[i]);

  return root;
}

int addToArray(node * root, int u[], int i)
{
  if (root == nullptr)
    return i;

  if (root->left != nullptr)
    i = addToArray(root->left, u, i);

  u[i] = root->key;
  i++;
  
  if (root->right != nullptr)
      i = addToArray(root->right, u, i);

  return i;
}

void loadVec(node * root, int u[], int n)
{
  /* 
varre árvore enraizada em root  usando percurso em ordem simétrica e coloca cada chave visitada progressivamente em u  na ordem de visitação da árvore. u.
*/
  addToArray(root, u, 0);
}
