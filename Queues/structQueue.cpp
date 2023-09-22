#include<iostream>
using namespace std;

struct queue{
    int rear,front,size,cap;
    int *arr;
    queue(int c){
        cap=c;
        size=0;
        arr = new int[cap];
    }

    void enqueue(int x);
    void dequeue();
    int getRear();
    int getFront();
    void peek();
    bool isFull();
    bool isEmpty();
    void display();
};

bool queue::isFull(){
    return (cap==size);
}

bool queue::isEmpty(){
    return (size==0);
}

void queue::enqueue(int x){
    if(isFull()){
        cout<<"Queue is full"<<endl;
    }
    else{
        arr[size]=x;
        size++;
    }
}

void queue::peek(){
    if(isEmpty()){
        cout<<"Empty"<<endl;
    }
    else
        cout<<arr[size]<<endl;
}

void queue::dequeue(){
    if(isEmpty())
        cout<<"Empty"<<endl;
    else{
        for(int i=0;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;
    }
}

int queue::getFront(){
    if(isEmpty())
        return -1;
    else
        return 0;
}

int queue::getRear(){
    if(isEmpty())
        return -1;
    else
        return (size-1);
}

void queue::display(){
    if(isEmpty())
        cout<<"Empty"<<endl;
    else{
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){

}
