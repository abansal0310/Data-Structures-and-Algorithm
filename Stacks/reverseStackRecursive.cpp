#include<iostream>
#include<stack>
using namespace std;

int reverse(stack<int> &s){
    int a = s.top();
    if(s.empty()){
        return 0;
    }
    else{
        s.pop();
        reverse(s);
        s.push(a);
        cout<<s.top()<<" ";
    }
}

int main(){
    stack<int>temp;
    temp.push(10);
    temp.push(20);
    temp.push(30);
    temp.push(40);
    temp.push(50);

    reverse(temp);
}