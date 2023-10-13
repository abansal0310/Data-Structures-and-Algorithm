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

void show(Node *head){
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

void delHNode(Node *(&head)){
    Node *ptr = head;
    if(head==NULL){
        return;
    }
    Node *temp = head;
    head = temp->next;
    head->prev=NULL;
    delete temp;
}

void delPosNode(Node* head, int pos){
    Node *ptr = head;
    int i=1;
    while(ptr!=NULL && i<pos-1){
        ptr=ptr->next;
        i++;
    }
    Node *temp = ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    delete temp;
}

void delValNode(Node *head, int val){
    Node *ptr = head;
    while(ptr->next->data != val){
        ptr = ptr->next;
        if(ptr==NULL){
            cout<<"Error"<<endl;
            return;
        }
    }
    Node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev=ptr;
    delete temp;
}

int main(){
    Node *head = nullptr;
    push(head,10);
    push(head,20);
    push(head,30);
    push(head,40);
    push(head,50);

    delPosNode(head,2);
    delHNode(head);
    delValNode(head,20);
    show(head);
}