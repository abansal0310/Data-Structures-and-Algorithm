#include<iostream>
using namespace std;

struct Node{
    Node *next;
    Node *prev;
    int data;
    Node(int x){
        data=x;
        next = NULL;
        prev = NULL;
    }
};

void Fdisplay(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void Rdisplay(Node *head){
    Node *ptr = head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }

    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->prev;
    }
}

void push(Node *(&head), int x){
    Node *temp =new Node(x);
    if(head == NULL){
        head = temp;
        return;
    }
    Node *ptr = head;
    temp->next = head;
    head->prev = temp;
    head=temp;
}

int main(){
    Node *head =NULL;
    push(head,40);
    push(head,30);
    push(head,20);
    push(head,10);

    Fdisplay(head);
    Rdisplay(head);
}