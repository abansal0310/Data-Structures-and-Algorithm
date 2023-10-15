#include<iostream>
using namespace std;

struct Node{
    Node*prev,*next;
    int data;
    Node(int x){
        data=x;
        prev=next=NULL;
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
    Node *temp = new Node(x);
    if(head==NULL){
        head=temp;
        return;
    }
    Node *ptr=head;
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void delDuplicate(Node *&head){
    Node *ptr = head;
}

int main(){

}