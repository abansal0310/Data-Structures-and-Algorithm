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

void display(Node *head){
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void DelNode(Node *&head, int x) {
    Node *ptr = head;

    if (head->data == x) {
        head = ptr->next;
        delete ptr;
        return;
    }

    while (ptr->next != NULL && ptr->next->data != x) {
        ptr = ptr->next;
    }

    if (ptr->next != NULL) {
        Node *temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
}


int minNode(Node * &head){
    Node *ptr = head;
    int cmp = head->data;
    while(ptr != NULL){
        if(cmp>ptr->data)
            cmp=ptr->data;
        ptr=ptr->next;
    }
    DelNode(head, cmp);
    return cmp;
}

void addEnd(Node *(&head), int x){
    Node *ptr = head;
    Node *temp = new Node (x);
    if(head == nullptr){
        head = temp;
        return;
    }
    while(ptr->next != NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}

void selSort(Node* &head){
    Node *temp=NULL;
    while(head != NULL){
        int a = minNode(head);
        addEnd(temp,a);
    }
    display(temp);
}

int main(){

    Node *head = new Node(20);
    Node *num1 = new Node(60);
    Node *num2 = new Node(50);
    Node *num3 = new Node(30);
    Node *num4 = new Node(10);
    Node *num5 = new Node(40);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;
    num4->next=num5;

    selSort(head);
}