#include<iostream>
using namespace std;

struct Node{
    Node *right,*left;
    int data;
    Node(int x){
        data=x;
        right=left=NULL;
    }
};

void inOrder(Node *root){
    Node *ptr = root;
    if(ptr == NULL){
        return;
    }
        
    inOrder(ptr->left);
    cout<<ptr->data<<" ";
    inOrder(ptr->right);
    
}

void preOrder(Node *root){
    Node *ptr = root;
    if(ptr==NULL){
        return;
    }

    cout<<ptr->data<<" ";
    preOrder(ptr->left);
    preOrder(ptr->right);

}

void postOrder(Node *root){
    Node *ptr = root;
    if(ptr==NULL){
        return;
    }

    postOrder(ptr->left);
    postOrder(ptr->right);
    cout<<ptr->data<<" ";
}


int main(){
    Node *root = new Node(10);
    Node *num2 = new Node(20);
    Node *num3 = new Node(30);
    Node *num4 = new Node(40);
    Node *num6 = new Node(60);
    Node *num5 = new Node(50);
    Node *num7 = new Node(70);
    Node *num8 = new Node(80);

    root->left=num2;
    num2->left=num4;
    num2->right=num5;
    num5->left=num7;
    num5->right=num8;
    root->right=num3;
    num3->right=num6;

    cout<<"Inorder : ";
    inOrder(root);
    cout<<endl;

    cout<<"Preorder : ";
    preOrder(root);
    cout<<endl;

    cout<<"Postorder : ";
    postOrder(root);
    cout<<endl;
}