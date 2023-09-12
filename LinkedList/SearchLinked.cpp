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

int searchLinked(Node *head, int x){
    Node *temp =head;int i=1;
    while(temp->data!=x && temp->next!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp->next == NULL){
        return -1;
    }
    else{
        return i;
    }
}

int main(){
    Node *head = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);
    Node *num4 = new Node(50);

    head->next=num1;
    num1->next=num2;
    num2->next=num3;
    num3->next=num4;

    cout<<searchLinked(head,5)<<endl;
}