#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};


void sortInsert(Node *head, int data){
    Node *curr=head;
    Node *temp=new Node(data);

    while(curr!=NULL && curr->data<=data){
        curr=curr->next;
    }
    temp->next = curr;
    curr->next = temp;

    Node *ptr = head;

    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

int main()
{

    Node *head = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);
    Node *num4 = new Node(60);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;

    sortInsert(head,50);
}
