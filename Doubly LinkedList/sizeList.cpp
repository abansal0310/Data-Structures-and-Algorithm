#include<iostream>
using namespace std;

struct Node{
    Node *next;
    Node *prev;
    int data;
    Node(int x){
        next=prev=NULL;
        data=x;
    }
};

void display(Node *head){
    Node *ptr=head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void push(Node *(&head), int x){
    Node *temp = new Node(x);
    if(head==NULL){
        head=temp;
        return;
    }
    Node *ptr = head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}

void countEle(Node *head){
    Node *ptr = head;
    int i=0;
    while(ptr!= NULL){
        i++;
        ptr=ptr->next;
    }
    cout<<"Total Elements : "<<i<<endl;
}

int main(){
    Node *head = nullptr;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,50);

    countEle(head);
}