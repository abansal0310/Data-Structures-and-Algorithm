#include<iostream>
#include<queue>
using namespace std;

struct Stack{

    queue<int>q1;
    queue<int>q2;

    void push(int x);
    void display();
};

void Stack::push(int x){
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }

    q1.push(x);

    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

void Stack::display(){
    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
}

int main(){
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);

    s1.display();
}