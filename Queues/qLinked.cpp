#include<iostream>
using namespace std;

struct Node{
    Node *next;
    int data;
    Node(int x=0){
        data=x;
        next=nullptr;
    }
};

struct Queue{
    Node *front;
    Node *rear;
    int size,capacity;
    Queue(int x){
        capacity=x;
        size=0;
        front=rear=nullptr;
    }

    bool isEmpty();
    bool isFull();
    int peek();
    void enqueue(int x);
    void dequeue();
};

bool Queue::isEmpty(){
    if(size==0)
        return true;
    return false;
}

bool Queue::isFull(){
    if(size==capacity)
        return true;
    return false;
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"OverFlow"<<endl;
        return;
    }
    Node *temp = new Node(x);
    if(rear==nullptr){
        rear=temp;
        front=rear;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
    size++;
}

int Queue::peek(){
    if(isEmpty()){
        return -1;
    }
    return front->data;
}

void Queue::dequeue(){
    if(isEmpty()){
        cout<<"Underflow"<<endl;
        return;
    }
   
    Node *temp = front;
    front = front->next;
    free(temp);
}

int main(){
    struct Queue s(5);
    cout<<s.isEmpty()<<endl;
    s.enqueue(1);
    cout<<s.isEmpty()<<endl;
    s.enqueue(2);
    s.enqueue(3);
    s.enqueue(4);
    s.enqueue(5);
    cout<<s.isFull()<<endl;
    s.enqueue(6);
    s.dequeue();
    s.dequeue();
    cout<<s.peek()<<endl;
}