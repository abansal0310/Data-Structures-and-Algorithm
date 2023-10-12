#include<iostream>
using namespace std;

struct dequeue{
    int front,rear;
    int size;
    int arr[100];
    
    dequeue(int x){
        front=rear=-1;
        size = x;
    }

    void insertFront(int x);
    void insertEnd(int y);
    void deleteFront();
    void deleteEnd();
    bool isFull();
    bool isEmpty();
    int getFront();
    int getRear();

};

bool dequeue::isFull(){
    return((rear+1 == front)||(front==0 && rear==size-1));
}
bool dequeue::isEmpty(){
    return(front ==-1);
}

void dequeue::insertFront(int x){
    if(isFull()){
        cout<<"OverFlow"<<endl;
        return;
    }
    if(front == -1){
        front=0;
        rear=0;
    }
    else if(front==0){
        front =size-1;
    }
    else{
        front = front-1;
    }

    arr[front]=x;
}

void dequeue::insertEnd(int y){
    if(isFull()){
        cout<<"OverFlow"<<endl;
        return;
    }
    if(front==-1){
        front=0;
        rear=0;
    }
    else if(rear=size-1){
        rear = 0;
    }
    else{
        rear = rear+1;
    }
    arr[rear]=y;
}

void dequeue::deleteFront(){
    if(isEmpty()){
        cout<<"UnderFlow"<<endl;
        return;
    }
    if(front==rear){
        front=rear=-1;
    }
    else if(front = size-1){
        front=0;
    }
    else{
        front++;
    }
}

void dequeue::deleteEnd(){
    if(isEmpty()){
        cout<<"UnderFlow"<<endl;
        return;
    }
    if(front==rear){
        front=rear=-1;
    }
    else if(rear == 0){
        rear=size-1;
    }
    else{
        rear--;
    }
}

int dequeue::getFront(){
    if(isEmpty()){
        cout<<"Empty"<<endl;
        return -1;
    }
    return(arr[front]);
}

int dequeue::getRear(){
    if(isEmpty()){
        cout<<"Empty"<<endl;
        return -1;
    }
    return(arr[rear]);
}

int main(){
    dequeue dq(5);
    cout<<dq.isEmpty()<<endl;
    dq.insertFront(10);
    dq.insertEnd(50);
    dq.insertFront(20);
    cout<<dq.getFront()<<endl;
    cout<<dq.getRear()<<endl;
    dq.deleteEnd();
    cout<<dq.getRear()<<endl;
}