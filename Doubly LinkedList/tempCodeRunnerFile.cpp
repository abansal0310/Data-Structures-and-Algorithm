#include<iostream>
using namespace std;

struct Node{
    Node *next;
    Node *prev;
    int data;
    Node(int x){
        data=x;
        next=prev=NULL;
    }
};

void display(Node *head){
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void push(Node *(&head),int x){
    Node *ptr = head;
    Node *temp = new Node(x);
    if(head == NULL){
        head = temp;
        return;
    }

    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;   
}

void reverse(Node *(&head)){
    Node *ptr = NULL;
    Node *curr = head;
    if(head == NULL)
        return;

    else if(head->next == NULL)
        return;
    
    while(curr!=NULL){
        curr->prev = curr->next;
        ptr->prev = curr;
        curr->next=ptr;
        ptr = curr;
        curr = curr->prev;
    }

    head = ptr;
}

int main(){
    Node *head = nullptr;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,50);

    reverse(head);
    display(head);
}