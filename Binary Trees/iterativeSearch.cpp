#include <iostream>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int bSearch(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->data == x)
        {
            return 1;
        }
        else if (root->data > x)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return 0;
}

Node *newNode(Node *root, int x)
{
    Node *temp = new Node(x);
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    if (root->data > x)
    {
        root->left = newNode(root->left, x);
    }
    else
    {
        root->right = newNode(root->right, x);
    }

    return root;
}

int main()
{
    struct Node *root = NULL;
    root = newNode(root, 50);
    newNode(root, 30);
    newNode(root, 20);
    newNode(root, 40);
    newNode(root, 70);
    newNode(root, 60);
    newNode(root, 80);

    if (bSearch(root, 20))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}