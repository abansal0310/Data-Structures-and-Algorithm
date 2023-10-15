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

void push(Node *(&head), int data){
    Node *temp = new Node(data);
    if(head == NULL){
        head=temp;
        return;
    }
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = temp;
}

Node *delNode(Node *(&head), int x){
    Node *ptr = head;
    if(head->data = x){
        head=ptr->next;
        ptr->next = NULL;
        return ptr;
    }
    while(ptr->next->data!=x){
        Node *ptrr = ptr->next;
        ptr->next=ptrr->next;
        ptrr->next = NULL;
        return ptrr;
    }

}

void merge(Node *h1, Node *h2){
    Node *ptr1 = h1;
    Node *ptr2 = h2;

    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data>ptr2->data){
            //Node *temp = delNode(ptr)
        }
    }
}

int main(){

}