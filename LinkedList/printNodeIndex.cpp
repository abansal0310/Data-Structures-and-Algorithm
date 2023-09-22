#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
    Node (int x){
        data=x;
        next=nullptr;
    }
};

void nodeIndex(Node *head, int indx){
    Node *ptr = head;
    int i=0;
    while(i<indx){
        if(ptr->next == nullptr){
            cout<<"Invalid Index"<<endl;
            break;
        }
        ptr = ptr->next;
        i++;
    }

    cout<<"Data : "<<ptr->data<<endl;
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

    nodeIndex(head,2);
}
