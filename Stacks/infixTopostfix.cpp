#include<iostream>
#include<stack>
using namespace std;

int value(char x){
    if(x=='^')
        return 3;
    else if(x=='*' || x=='/')
        return 2;
    else if(x=='+' || x=='-')
        return 1;
    else
        return -1;
}

void conversion(string s){
    stack<char>ans;

    int str = s.length();
    string ns;

    for(int i=0;i<str;i++){ 
    }

}

int main(){

}