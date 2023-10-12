#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
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

void Isort(Node *head){
    for(Node *ptr = head; ptr!=NULL; ptr = ptr->next){
    }
}   

int main(){

}