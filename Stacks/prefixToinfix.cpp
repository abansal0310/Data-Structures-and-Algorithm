#include<iostream>
#include<stack>
#include<string>

using namespace std;

int presedence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else
        return 1;
}

bool isOperator(char c){
    if(c == '*' || c == '+' || c == '/' || c == '-' || c == '^'){
        return true;
    }
    else 
        return false;
}

void convert(string s){
    stack<char>ans;
    string result;
    int n = s.length();

    for(int i=0;i<n;i++){
        char c = s[i];
        
        if(isOperator(c)){
            ans.push(c);
        }
        
        else if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c <='9')){
            result += c;
            if(!ans.empty()){
                result += ans.top();
                ans.pop();
            }
        }
    }
    cout<<result<<endl;
}

int main(){
    string str = "*-A/BC-/AKL";
    convert(str);
}