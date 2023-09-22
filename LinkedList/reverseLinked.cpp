#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;

    Node(int x=0){
        data=x;
        next = nullptr;
    }
};

void reverseList(Node *head){
    Node *prev=nullptr;
    Node *curr = head;
    Node *Next=nullptr;

    while(curr != nullptr){
        Next=curr->next;
        curr->next = prev;
        prev=curr;
        curr=Next;
    }
    head = prev;

    Node *print = head;
    while(print != nullptr){
        cout<<print->data<<"->";
        print = print->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node *head1 = new Node(1);
    Node *num1 = new Node(2);
    Node *num2 = new Node(3);
    Node *num3 = new Node(4);
    Node *num4 = new Node(5);
    Node *num5 = new Node(6);
    
    head1->next = num1;
    num1->next = num2;
    num2->next = num3;
    num3->next = num4;
    num4->next = num5;

    reverseList(head1);
}