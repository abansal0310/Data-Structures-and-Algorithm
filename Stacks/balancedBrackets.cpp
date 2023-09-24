#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool balanced(string str){
    stack<char>temp;
    int n = str.length();
    for(int i=0;i<n;i++){
        char c = str[i];
        if(c == '(' || c =='{' || c == '[' )
            temp.push(c);
        else if(c == ')' || c == '}' || c == ']'){
            char opening = temp.top();
            temp.pop();
            if((c == ')' && opening != '(') || (c == '}' && opening != '{') || (c == ']' && opening != '[')){
                return false;  // Mismatched brackets.
            }
        }
    }
    if(temp.empty()){
        return true;
    }
    return false;
}

int main(){
    string st = "{()}[]";
    if(balanced(st))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}