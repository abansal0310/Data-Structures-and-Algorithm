#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
    Node(int x=0){
        data=x;
        next=prev=NULL;
    }
};

void push(Node *(&head),int x){
    Node *temp = new Node(x);
    if(head==NULL){
        head=temp;
        return;
    }
    Node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}

void display(Node *head){
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void addList(Node *(&head), int x){
    Node *ptr = head;
    Node *temp = new Node(x);
    if(head==NULL){
        head=temp;
        return;
    }
    while(ptr->next != NULL && ptr->next->data<x){
        ptr=ptr->next;
    }
    temp->next = ptr->next;
    temp->prev=ptr;
    ptr->next->prev=temp;
    ptr->next =temp;

    display(head);
}

int main(){
    Node *head = nullptr;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,60);
    push(head,70);

    addList(head,50);
}