#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x){
        data=x;
        next=nullptr;
    }
};

Node *addLinkedList(Node *l1, Node *l2){
        Node *head1;
        Node *temp = head1;
        Node *temp1 = l1;
        Node *temp2 = l2;
        int carry = 0;
        while(temp1->next != NULL && temp2->next != NULL ){
            int a = temp1->data;
            int b = temp2->data;
            int c = (a+b+carry)%10;
            temp->data = c;
            temp=temp->next;
            carry = (a+b+carry)/10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1->next !=NULL){
            temp->data = temp1->data;
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2->next !=NULL){
            temp->data = temp2->data;
            temp=temp->next;
            temp2=temp2->next;
        }
        return head1;
}

void display(Node *head){
    Node *temp = head;
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node *head1 = new Node(1);
    Node *num1 = new Node(2);
    Node *num2 = new Node(3);

    Node *head2 = new Node(8);
    Node *num3 = new Node(9);
    Node *num4 = new Node(5);
    Node *num5 = new Node(7);

    head1->next = num1;
    num1->next = num2;

    head2->next = num3;
    num3->next = num4;
    num4->next = num5;

    Node *aHead = addLinkedList(head1,head2);
    display(aHead);
}