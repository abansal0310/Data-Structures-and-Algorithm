#include<iostream>
using namespace std;

struct Node{
    Node *left,*right;
    int data;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

void inOrder(Node *root){
    if(root==NULL){
        cout<<"ERROR"<<endl;
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void insert(Node *(&root),int x){
    Node *temp = new Node(x);
    Node *ptr = root;
    if(root == NULL){
        root=temp;
        return;
    }
    
    while(ptr != NULL){
        if(ptr->data>x){
            ptr=ptr->left;
        }
        else if(ptr->data<x){
            ptr=ptr->right;
        }
    }
    ptr=temp;
}

int main(){
    Node *root = nullptr;
    insert(root,50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inOrder(root);
}
