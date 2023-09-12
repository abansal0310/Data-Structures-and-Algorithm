#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x){
        data=x;
        next=NULL;
    }
};

int middleLinked(Node *head){
    Node *ptr1 = head;
    Node *ptr2 = head;
    while(ptr2!=NULL && ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2= ptr2->next->next;
    }

    return (ptr1->data);
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

   cout<<"Answer is : "<<middleLinked(head)<<endl;


}