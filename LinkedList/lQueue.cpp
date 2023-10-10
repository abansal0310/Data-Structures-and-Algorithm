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

struct Queues{
    Node *front;
    Node *rear;
    int size,capacity;
    Queues(int x){
        capacity=x;
        size=0;
        front = NULL;
        rear = front;
    }

    bool isEmpty();
    bool isFull();
    void enqueue();
    void dequeue();
    int peek();
};

bool Queues::isEmpty(){

}

bool Queues::isFull(){

}

void Queues::enqueue(){

}


int main(){

}