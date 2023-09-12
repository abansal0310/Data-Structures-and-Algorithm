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

void display(Node *head){
    Node *ptr = head;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

void rDuplicate(Node *head){
    Node *ptr = head;
    Node *curr = ptr->next;
    while(curr->next !=NULL){
        Node *temp = new Node();
        if(ptr->data == curr->data){
            temp = curr;
            curr=curr->next;
            delete temp;
        }
        else{
            ptr->next = curr;
            curr=curr->next;
        }
    }
    display(head);
}


int main(){

    Node *head1 = new Node(1);
    Node *num1 = new Node(1);
    Node *num2 = new Node(2);
    Node *num3 = new Node(3);
    
    head1->next = num1;
    num1->next = num2;
    num2->next = num3;

    rDuplicate(head1);
}