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

void fromEndLength(Node *head, int x){
    Node *ptr = head;
    Node *curr = head;
    int n=1;
    while (ptr->next != NULL)
    {
        n++;
        ptr=ptr->next;
    }
    n=n-x;
    for(int i=0;i<n;i++){
        curr=curr->next;
    }
    cout<<curr->data<<endl;  
}



int main(){
    Node *head1 = new Node(1);
    Node *num1 = new Node(2);
    Node *num2 = new Node(3);
    Node *num3 = new Node(4);
    
    head1->next = num1;
    num1->next = num2;
    num2->next = num3;

    fromEndLength(head1,1);

}