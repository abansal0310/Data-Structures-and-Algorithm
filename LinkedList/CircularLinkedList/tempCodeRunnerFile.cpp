#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
    Node(int x){
        data=x;
        next=NULL;
    }
};

void display(Node *head){
    Node *temp = head;
    while(temp != head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);

    head->next = num1;
    num1->next = num2;
    num2->next = num3;
    num3->next = head;

    display(head);
}