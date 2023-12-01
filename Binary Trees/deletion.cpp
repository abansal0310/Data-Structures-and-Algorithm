#include <iostream>
using namespace std;

struct Tree
{
    Tree *left, *right;
    int data;

    Tree(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void del(Tree *root, int x)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left->data == x)
    {
        Tree *ptr = root->left;
        root->left = ptr->left;
        delete ptr;
    }
    else if (root->right->data == x)
    {
        Tree *ptr = root->right;
        root->right = ptr->right;
        delete ptr;
    }

    del(root->left, x);
    del(root->right, x);
}

void printLeaf(Tree *root)
{
    if (root == NULL)
    {
        return;
    }

    printLeaf(root->left);
    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }
    printLeaf(root->right);
}

int main()
{
    Tree *root = new Tree(10);
    root->left = new Tree(20);
    root->right = new Tree(30);
    root->right->right = new Tree(70);
    root->right->right->right = new Tree(80);
    root->left->left = new Tree(40);
    root->left->right = new Tree(50);

    printLeaf(root);
}