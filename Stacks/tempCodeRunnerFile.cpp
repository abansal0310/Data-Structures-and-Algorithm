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

struct stack{
    Node *head;
    int size=0;
    void push(int x);
    void pop();
    void isEmpty();
    void peek();
};

void stack::push(int x){
    Node *prev = new Node(x);
    prev->next = head;
    head = prev;
    size++;
}

void stack::pop(){
    if(head == NULL){
        cout<<"UnderFlow"<<endl;
        exit(1);
    }
    cout<<head->data<<endl;
    Node *temp = head;
    head=head->next;
    delete temp;
    size--;
}

void stack::isEmpty(){
    if(size==0){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}

void stack::peek(){
    if(size==0){
        cout<<"UnderFlow"<<endl;
        exit(1);
    }
    else{
        cout<<head->data<<endl;
    }
}

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.isEmpty();

    s.pop();
    s.pop();

    s.peek();
    s.isEmpty();
    s.pop();
    s.isEmpty();
    
}