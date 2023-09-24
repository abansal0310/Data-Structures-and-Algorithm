#include<iostream>
#include<stack>
#include <bits/stdc++.h>
#include<string>
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

    int n = s.length();
    string result;

    for(int i=0;i<n;i++){ 
        auto c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c <='9')){
            result += c;
        }
        else if(c == '(')
            ans.push(c);
        else if(c == ')'){
            while(ans.top() != '('){
                result += ans.top();
                ans.pop();
            }
            ans.pop();
        }
        else{
            while(!ans.empty() && value(s[i])<= value(ans.top())){
                result += ans.top();
                ans.pop();
            }
            ans.push(c);
        }
    }
    
    while(!ans.empty()){
        result += ans.top();
        ans.pop();
    }

    cout<<result<<endl;
}

int main(){
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    conversion(exp);

    return 0;
}