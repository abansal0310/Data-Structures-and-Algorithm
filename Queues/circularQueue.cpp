#include<iostream>
using namespace std;

struct Queue
{
    int rear,front;
    int *arr;
    int size;

    Queue(int x){
        rear=front=-1;
        size=x;
        int *arr = new int[size];
    }

    bool isFull();
    bool isEmpty();
    void enqueue(int x);
    int dequeue();
    void display();
};

bool Queue::isFull(){
    if((front==0 && rear == size-1)||((rear+1)%size==front)){
        return true;
    }
    return false;
}

bool Queue::isEmpty(){
    return (front == -1);
}

void Queue::enqueue(int x){
    if(isFull()){
        cout<<"Full"<<endl;
        return;
    }

    if(front == -1){
        front=0;
        rear=0;
        arr[rear]=x;
    }
    else if(rear == size-1 && front != 0){
        rear=0;
        arr[rear]=x;
    }
    else{
        rear++;
        arr[rear]=x;
    }
}

int Queue::dequeue(){
    if(isEmpty()){
        cout<<"Empty"<<endl;
        return 0;
    }
    int data = arr[front];
    arr[front]=0;
    if(front == rear){
        front=-1;
        rear=-1;
    }
    else if(front = size-1)
        front=0;
    else
        front++;

    return data;
}

void Queue::display(){

    if(isEmpty()){
        cout<<"Empty"<<endl;
        return;
    }
    if(rear>=front){
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        for(int i=front;i<size;i++){
            cout<<arr[i]<<" ";
        }
        for(int i=0;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
    }

}
 

int main(){
    Queue q1(5);
    cout<<q1.isFull()<<endl;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.dequeue();
   q1.enqueue(4);
   q1.dequeue();
   q1.enqueue(5);
   q1.display();

}