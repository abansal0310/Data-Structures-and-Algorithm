#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
    Node(int x=0){
        data=x;
        next=NULL;
    }
};

class Stack{
    public:
    int size;
    int top;
    Node *front;
    Node *temp;
    Stack(int x){
        size=x;
        top =-1;
        front = nullptr;
        //Node *ptr = new Node();
    }

    bool isEmpty();
    bool isFull();
    int peek();
    void push(int x);
    void pop();

};

bool Stack::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}

bool Stack::isFull(){
    if (top==size-1)
    {
        return true;
    }
    return false;  
}

void Stack::push(int x){
    if(isFull()){
        cout<<"Overflow"<<endl;
        return;
    }
    Node *num = new Node(x);
    if(front == NULL){
        front = num;
    }
    else{
        num->next = front;
        front =num;
    }
    top++;
}

void Stack::pop(){
    if(isEmpty()){
        cout<<"Stack UnderFlow"<<endl;
        return;
    }
    if(front ->next == NULL){
        front==NULL;
    }
    else{
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    top--;
}

int Stack::peek(){
    Node *curr = front;
    return front->data;
}


int main(){
    struct Stack s(5);
    cout<<s.isEmpty()<<endl;
    s.push(1);
    cout<<s.isEmpty()<<endl;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<s.isFull()<<endl;
    s.push(6);
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
}