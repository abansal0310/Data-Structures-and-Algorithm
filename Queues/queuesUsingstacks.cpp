 
#include<iostream>
#include<Stack>
using namespace std;

struct Queues
{
    stack<int>s1;
    stack<int>s2;

    void enqueue(int x);
    void display();
};

void Queues::enqueue(int x){
    s1.push(x);
}

void Queues::display(){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    while(!s2.empty()){
        cout<<s2.top()<<" ";
        s2.pop();
    }
}


int main(){
    Queues q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);

    q1.display();

}



