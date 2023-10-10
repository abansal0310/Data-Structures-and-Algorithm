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

void transverse(Node *head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
}

void addLast(Node* head, int num){
    Node *var = new Node(num);
    Node *temp =head;

    if(head==NULL){
        head=var;
        return;
    }
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next = var;
    // transverse(head);
}

void merge(Node *head1, Node *head2)
{
    Node head(0);
    Node *temp = &head;
    Node *temp1 = head1;
    Node *temp2 = head2;

    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1->data == temp2->data){
            //addLast(head,temp1->data);
            temp = temp1;
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }

        else if(temp1->data > temp2->data){
            //addLast(head,temp2->data);
            temp = temp2;
            temp2=temp2->next;
            temp=temp->next;
        }

        else if(temp1->data<temp2->data){
            //addLast(head,temp1->data);
            temp=temp1;
            temp1=temp1->next;
            temp=temp->next;
        }
    }

    Node *tempp1 = head1;
    Node *tempp2 = head2;

    while(tempp1 != nullptr){
        //addLast(head,temp1->data);
        temp = temp1;
        temp1=temp1->next;
        temp=temp->next;
    }

    while(tempp2 != nullptr){
        //addLast(head,temp2->data);
        temp = temp2;
        temp2=temp2->next;
        temp=temp->next;
    }

    transverse(head);
}

int main(){
    Node *head1 = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);

    Node *head2 = new Node(5);
    Node *numm1 = new Node(10);
    Node *numm2 = new Node(15);
    Node *numm3 = new Node(20);

    head1->next=num1;
    num1->next=num2;
    num2->next=num3;

    head2->next = numm1;
    numm1->next = numm2;
    numm2->next = numm3;

    merge(head1,head2);
}