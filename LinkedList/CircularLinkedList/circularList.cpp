#include<iostream>
using namespace std;

struct  Node{
    int data;
    Node *next;
    Node(int x=0){
        data=x;
        next = NULL;
    }
};

void display(Node *head){
    Node *temp = head;
    //Transverseal
    while(temp->next != head){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}

void insert(Node *head, int pos, int num){
    Node *temp = head;
    Node *value = new Node(num);
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    value->next = temp->next;
    temp->next = value;
}

void delNode(Node *head, int pos){
    Node *curr = head;
    for(int i=1;i<pos-1;i++){
        curr=curr->next;
    }
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
}


int main(){
    Node *head = new Node(10);
    Node *num1 = new Node(20);
    Node *num2= new Node(30);
    Node *num3 = new Node(40);
    Node *num4 = new Node(50);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;
    num4->next=head;

    insert(head,6,60);
    delNode(head,3);
    display(head);
    // circularList(head);
}