#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int front;
    Stack(int x){
       int *arr = new int();
        front = -1;
        size = x;
    }

    bool isFull();
    bool isEmpty();
    void push(int x);
    void pop();
    int peak();
};

bool Stack::isFull(){
    if(front == size-1){
        return true;
    }
    else
        return false;
}

bool Stack::isEmpty(){
    if(front == -1){
        return true;
    }
    else
        return false;
}

void Stack::push(int x){
    if(isFull()){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    ++front;
    arr[front]=x;
}

void Stack::pop(){
    if(isEmpty()){
        cout<<"Stack Underflow"<<endl;
        return;
    }
    //int *temp = &arr[front];
    --front;
    //delete temp;
}

int Stack::peak(){
    int temp = arr[front];
    return temp;
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
    cout<<s.peak()<<endl;

}