#include<iostream>
using namespace std;

struct dequeue{
    int front,rear;
    int size;
    int *arr;
    
    dequeue(int x){
        front=rear=-1;
        size = x;
        int *arr = new int(size);
    }

    void insertFront(int x);
    void insertEnd(int y);
    void deleteFront();
    void delteEnd();
};

void dequeue::insertFront(int x){
    if((rear==size-1 && front ==0)||(front=rear+1)){
        cout<<"OverFlow"<<endl;
        return;
    }
    if(rear == -1){
        rear=0;
    }
    front = (front+1)%size;
    arr[front]=x;
}

void dequeue::insertEnd(int y){
    if( )
}



int main(){

}