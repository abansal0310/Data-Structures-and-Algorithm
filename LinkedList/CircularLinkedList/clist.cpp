#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
    Node(int x=0){
        data=x;
        next=NULL;
    }
};

void displayy(Node *head){
    Node *temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp != head);
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

    displayy(head);
}