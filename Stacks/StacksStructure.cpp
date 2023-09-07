#include<iostream>
using namespace std;

//Using Arrays
struct stack
{
    int top;
    int arr[MAX_PATH];

    stack(){ top=-1;}
    bool push(int x);
    int pop();
    bool isEmpty();
};

bool stack::push(int x){
    if(top>MAX_PATH-1){
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    else{
        arr[++top]=x;
        cout<<"Pushed Successfully"<<endl;
        return true;
    }

}

int stack::pop(){
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        int x = arr[top];
        arr[top]=0;
        top--;
        cout<<x<<" ";
        return x;
    }
}

bool stack::isEmpty(){
    if(top==-1){
        cout<<"Empty"<<endl;
        return false;
    }
    else{
        cout<<"Not Empty"<<endl;
        return true;
    }
}


int main(){
    stack s;
    s.pop();
    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();
    s.pop();
    s.pop();

    s.isEmpty();
}