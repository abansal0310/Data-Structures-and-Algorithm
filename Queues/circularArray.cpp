#include<iostream>
using namespace std;

struct Queue{
    int rear,first,cap,size=0;
    int *arr;
    Queue(int x){
        cap=x;
        first=0;
        rear=0;
        arr = new int[cap];
    }

    void enqueue(int x);
    void dequeue();
    int getRear();
    int getFront();
    bool isFull();
    bool isEmpty();
    void display();

};

bool Queue::isEmpty(){
    return (rear==0);
}

bool Queue::isFull(){
    return (rear==cap);
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Overflow"<<endl;
    }
    else{
        int rear = getRear();
        rear = (rear+1)%cap;
        arr[rear]=x;
        size++;
    }
}

void Queue::dequeue(){
    if(isEmpty)
        cout<<"Underflow"<<endl;
    else{
        first = (first+1)%cap;
        size--;
    }
}

int Queue::getRear(){
    if(isEmpty())
        return -1;
    else
        return (first+size-1)%cap;
}

int main(){

}