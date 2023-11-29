#include <iostream>
using namespace std;

struct BST
{
    int data;
    BST *left, *right;

    BST(int x)
    {
        left = right = NULL;
        data = x;
    }
};

void Kprint(BST *root, int k)
{
    BST *ptr = root;
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
    }

    Kprint(root->left, k - 1);
    Kprint(root->right, k - 1);
}

int main()
{
    BST *root = new BST(10);
    root->left = new BST(20);
    root->right = new BST(30);
    root->right->right = new BST(70);
    root->right->right->right = new BST(80);
    root->left->left = new BST(40);
    root->left->right = new BST(50);

    Kprint(root, 2);
}