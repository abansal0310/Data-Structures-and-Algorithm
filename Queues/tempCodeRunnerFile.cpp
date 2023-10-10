#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

// void nNode(Node *head, int key){
//     Node *ptr = head;
//     Node *fptr = head;

//     int i=1;

//     while(i<key){
//         i++;
//         fptr=fptr->next;
//     }

//     while(fptr->next != NULL){
//         fptr=fptr->next;
//         ptr=ptr->next;
//     } 

//     cout<<ptr->data<<endl;
// }

void display(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void recPrint(Node *head){
    Node *temp=head;
    if(head==NULL){
        return;
    }
    
    recPrint(temp->next);
    cout<<temp->data<<" ";
}

Node *recReverse(Node *head){
    if(head==NULL){
        return NULL;
    }
    else if(head->next == NULL){
        return head;
    }
    else{
        Node *n1=recReverse(head->next);
        n1->next = head;
        head->next = NULL;
        return n1;
    }
    //cout<<head->data<<endl;
    //display(head);
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

    //nNode(head,3);
    //recPrint(head);
    Node *temp;
    temp=recReverse(head);
    display(temp);
}