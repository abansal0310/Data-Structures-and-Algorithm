#include<iostream>
using namespace std;

struct Node{
    Node *next;
    Node *prev;
    int data;
    Node(int x){
        next=prev=NULL;
        data=x;
    }
};

void display(Node*head){
    Node *ptr = head;
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void push(Node *(&head),int x){
    Node *temp = new Node(x);
    if(head==NULL){
        head=temp;
        return;
    }
    Node *ptr = head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
}

//Not Sorted
void pairSum(Node *head, int sum){

    for(Node *ptr = head; ptr!=NULL;ptr=ptr->next){
        for(Node *ptrr = ptr->next; ptrr!=NULL; ptrr=ptrr->next){
            if(ptr->data+ptrr->data==sum){
                cout<<ptr->data<<","<<ptrr->data<<endl;
            }
        }
    }
}

//Sorted
void SpairSum(Node *head, int sum){
    
}


int main(){
    Node *head = nullptr;
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);
    push(head,6);
    push(head,7);
    push(head,8);
    push(head,9);
    push(head,10);

    pairSum(head,7);
}