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


int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(40);
}