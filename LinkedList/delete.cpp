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
    while(ptr->next != NULL){
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}

void deletePosition(Node *head, int pos){
    Node *curr = head;
    int i=1;
    while(i<pos-1 && curr!=NULL){
        i++;
        curr=curr->next;
    }
    Node *temp = curr->next;
    Node *ptr = temp->next;
    curr->next = ptr;
    delete temp;

}

Node* deleteFirst(Node *head){
    Node *temp = head;
    head=head->next;
    delete temp;
    return head;
}

void deleteLast(Node *head){
    Node *temp=head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp=NULL;
}

void deleteNode(Node *head, int x, int n){
    if(x==1)
        head = deleteFirst(head);
    else if(x==n)
        deleteLast(head);
    else
        deletePosition(head,x);

    display(head);
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

    deleteNode(head,1,6);
}

