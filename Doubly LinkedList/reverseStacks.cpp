#include<iostream>
#include<stack>
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


void display(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

void revStack(Node *(&head)){
    stack<int>s;
    Node *ptr=head;
    while(ptr != NULL){
        s.push(ptr->data);
        ptr=ptr->next;
    }

    ptr = head;

    while(!s.empty()){
        ptr->data = s.top();
        s.pop();
        ptr=ptr->next;
    }
}

int main(){
    Node *head = nullptr;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,50);

    revStack(head);
    display(head);
}