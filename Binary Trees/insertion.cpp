#pragma region

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

void insert(Tree *&root, int x)
{

    Tree *temp = new Tree(x);
    // Tree * &ptr = root;
    if (root == NULL)
    {
        root = temp;
        return;
    }

    if (root->data > x)
    {
        insert(root->right, x);
    }

    else if (root->data < x)
    {
        insert(root->left, x);
    }
}

void show(Tree *root)
{
    Tree *ptr = root;
    if (ptr == NULL)
    {
        return;
    }
    show(ptr->left);
    cout << ptr->data << " ";
    show(ptr->right);
}

int main()
{
    Tree *root = NULL;
    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 40);

    show(root);
}

#pragma endregion