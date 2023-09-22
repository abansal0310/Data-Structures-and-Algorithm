#include<iostream>
using namespace std;

struct Node{
    Node *next = nullptr;
    int data;
    Node(int x){
        data=x;
        next = nullptr;
    }
};

void moveLastFirst(Node *head){
    Node *curr = head;
    while(curr->next!= nullptr){
        curr = curr->next;
    }
    int temp = curr->data;
    curr = nullptr;

    Node *ptr = new Node(temp);
    ptr->next = head;
    head = ptr;

    Node *move = head;
    while(move->next != nullptr){
        cout<<move->data<<" ";
        move = move->next;
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

    moveLastFirst(head);

}