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
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

void addBack(Node *(&head),int x){
    Node *ptr = head;
    Node *temp = new Node(x);
    if(head==NULL){
        head=temp;
        return;
    }
   
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    ptr->next = temp;
}

void merge(Node *h1, Node *h2){
    Node *ptr1 = h1;
    Node *ptr2 = h2;

    Node *head=NULL;

    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data >= ptr2->data){
            addBack(head,ptr2->data);
            ptr2=ptr2->next;
        }
        else if(ptr1->data <= ptr2->data){
            addBack(head,ptr1->data);
            ptr1=ptr1->next;
        }
    }

    while(ptr1 != NULL){
        addBack(head,ptr1->data);
        ptr1=ptr1->next;
    }
    while(ptr2 != NULL){
        addBack(head,ptr2->data);
        ptr2=ptr2->next;
    }
    display(head);
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(Node *head){
    // Sort LL using Address Swpping
    for(Node *pptr = head; pptr !=nullptr; pptr=pptr->next){
        bool flag = true;
        for(Node *ptr = head; ptr->next!=nullptr; ptr=ptr->next){
            if(ptr->data>ptr->next->data){
                swap(ptr->data,ptr->next->data);
                flag=false;
            }
        }
        if(flag==true)
            break;
    }
    display(head);
}

int main(){
    Node *head1 = new Node(10);
    Node *num1 = new Node(20);
    Node *num2 = new Node(30);
    Node *num3 = new Node(40);

    Node *head2 = new Node(5);
    Node *numm1 = new Node(10);
    Node *numm2 = new Node(15);
    Node *numm3 = new Node(20);

    head1->next=num1;
    num1->next=num2;
    num2->next=num3;

    head2->next = numm1;
    numm1->next = numm2;
    numm2->next = numm3;

    Node *head = new Node(10);
    Node *nu1 = new Node(5);
    Node *nu2 = new Node(3);
    Node *nu3 = new Node(20);
    Node *nu4 = new Node(25);
    Node *nu5 = new Node(4);

    head->next=nu1;
    nu1->next=nu2;
    nu2->next=nu3;
    nu3->next=nu4;
    nu4->next=nu5;

    sort(head);
   // merge(head1,head2);
}