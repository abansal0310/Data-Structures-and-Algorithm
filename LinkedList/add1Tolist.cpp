#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x=0){
        data=x;
        next=NULL;
    }
};

void addOne(Node *head){
    Node *pos = head;
    int num=0;

    while(pos != NULL){
        num=num*10+pos->data;
        pos = pos->next;
    }

    delete pos;
    num++;

    Node *curr = head;
    while(curr != NULL){
        curr->data = num%10;
        num = num/10;
        curr=curr->next;
    }

    Node *print = head;
    while(print!=NULL){
        cout<<print->data<<" ";
        print=print->next;
    }
}

int main(){
    Node *head = new Node(1);
    Node *num1 = new Node(9);
    Node *num2 = new Node(9);
    Node *num3 = new Node(9);
    //Node *num4 = new Node(50);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    //num3->next=num4;

    addOne(head);
}