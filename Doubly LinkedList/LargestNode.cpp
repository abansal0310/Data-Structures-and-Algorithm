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

void display(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
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

int LargestNode(Node *head){
    Node *ptr = head->next;
    int maxNode = head->data;
    while(ptr!=NULL){
        if(ptr->data>maxNode){
            maxNode=ptr->data;
        }
        ptr=ptr->next;
    }
    cout<<"Largest Node : "<<maxNode<<endl;
}

int main(){
    Node *head = nullptr;
    push(head,60);
    push(head,20);
    push(head,90);
    push(head,30);
    push(head,50);

    LargestNode(head);

}