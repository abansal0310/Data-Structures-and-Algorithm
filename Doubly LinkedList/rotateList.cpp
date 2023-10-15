#include<iostream>
using namespace std;

struct Node{
    Node *next;
    Node *prev;
    int data;
    Node(int x){
        data = x;
        prev=next=NULL;
    }
};

void show(Node *(head)){
    Node *ptr = head;
    while(ptr!= nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void push(Node*(&head),int x){
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

void rotate(Node *(&head), int k){
    for(int i=1;i<=k;i++){

        Node *ptr = head;
        Node *ptrr=head;
        
        
        while(ptrr->next!=NULL){
            ptrr=ptrr->next;
        }

        head=head->next;
        ptr->prev=ptrr;
        ptrr->next=ptr;
        ptr->next=NULL;
        head->prev=NULL;
    }
    
}

int main(){

    Node *head = nullptr;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,50);
    //show(head);

    rotate(head,3);
    show(head);
}