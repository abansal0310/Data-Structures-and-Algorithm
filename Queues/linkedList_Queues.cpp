#include<iostream>
using namespace std;
struct Node{
    Node *next;
    int data;

    Node(int x){
        next=NULL;
        data=x;
    }
};

struct Queue{
    Node *front;
    Node *rear;
    int size;
    Queue(int x){
        front=nullptr;
        rear=front;
        size=x;
    }

    void enqueue(int x);
    void dequeue();
    bool isEmpty();
    bool isFull();
    void display();

};

void Queue::enqueue(int x){
    Node *temp = new Node(x);
    if(isFull()){
        cout<<"Full"<<endl;
        return;
    }
}

int main(){

}