#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x){
        next = nullptr;
        data=x;
    }
};

void moveMiddle(Node *head){
    Node *curr = head;
    Node *help = head;int i=0;

    while(help->next != NULL && help != NULL){
        curr = curr->next;
        help = curr->next;i++;
    }
    int temp = curr->data;
    Node *pos = head;
    for(int j=1;j<i;j++){
        pos = pos->next;
    }
    pos->next = pos->next->next;
    delete curr;

    Node *add = new Node(temp);
    add->next = head;
    head = add;

    Node *me = head;

    while(me->next != NULL){
        cout<<me->data<<" ";
        me = me->next;
    }
}

int main(){
    Node *head = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);
    Node *num4 = new Node(50);
    Node *num5 = new Node(60);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;
    num4->next=num5;

    moveMiddle(head);
}