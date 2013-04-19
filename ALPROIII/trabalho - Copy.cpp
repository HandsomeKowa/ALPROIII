#include <iostream>
#include <cmath>
#define MAX 4000000

using namespace std;

struct node
{
    int item;
    node *left;
    node *right;
    node(int x)
    {
        item = x;
        left = NULL;
        right = NULL;
    }
};

/*bool exist (node *&root, int x)
{
    if (root == NULL)
      return false;
    else
        if (x == root->item)
            return true;
    else
        if (x < root->item)
            return exist(root->left, x);
    else
        return exist(root->right, x);
}*/

bool confirma(double n)
{
    if (n - (int)n == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void addNode (node *&root, int x)
{
    if (root == NULL)
    {
        root = new node(x);
    }
    else
    {
        if (x == root->item)
            return;
        else
        {
            if (x < root->item)
                addNode(root->left, x);
            else
                addNode(root->right, x);
        }
    }
}

void treeShow (node *root)
{
    if (root != NULL)
    {
        cout << endl << root->item;
        treeShow(root->left);

        treeShow(root->right);
    }
}
int countNodes(node *node) {
      // Count the nodes in the binary tree to which node
      // points.  Return the answer.
   if ( node == NULL ) {
           // Tree is empty, so it contains no nodes.
      return 0;
   }
   else {
          // Add up the root node and the nodes in its two subtrees.
      int leftCount = countNodes( node->left );
      int rightCount = countNodes( node->right );
      return  1 + leftCount + rightCount;
   }
} // end countNodes()

int main ()
{
    node *root;
    root = NULL;
    for (int i = MAX/2; i<=MAX; i++)
    {
        if(confirma(sqrt(i)))
            addNode(root, i);
    }
    for (int i = 0; i < MAX/2; i++)
    {
        if(confirma(sqrt(i)))
            addNode(root, i);
    }
    cout << "Arvore criada " << countNodes(root->right)+countNodes(root->left)+1 << endl;
    //cin.ignore(1000, '\n');
    treeShow(root);
}
