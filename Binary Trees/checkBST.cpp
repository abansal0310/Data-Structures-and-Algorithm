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

Node *insert(Node *root, int x)
{
    Node *temp = new Node(x);
    if (root == NULL)
    {
        root = temp;
        return root;
    }

    if (root->data > x)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }

    return root;
}

int checkBST(Node *root)
{

    if (root == NULL)
    {
        return -1;
    }
    else
    {
        while (root != NULL)
        {
            int x = root->data;
            if (x < root->left->data || x > root->right->data)
            {
                return 0;
            }
            else
            {
            }
        }
    }
}

int main()
{
}