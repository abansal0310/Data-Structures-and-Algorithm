#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
    Node(int x){
        data=x;
        next=NULL;
    }
};

Node *revRecursion(Node *p){
    Node *head;
    if(p->next ==NULL){
        head=p;
    }
        
    Node *temp = revRecursion(p->next);
    p->next= head->next->next;
    head=p;
    p=p->next;

    return p;
}

int main(){

}