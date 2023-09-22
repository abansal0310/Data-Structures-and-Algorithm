#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x=0){
        data=x;
        next=nullptr;
    }
};

void push(Node **head, int data){
    Node *temp = new Node(data);
    temp->next = (*head);
    (*head) = temp;
}

int main(){
    Node *head = new Node(10);
    push(&head,20);
    push(&head,30);
    push(&head,40);

    while(head != nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }

}