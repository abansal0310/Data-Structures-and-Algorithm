#include<iostream>
#include<string>
#include<stack>
using namespace std;

int value(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void convert( string s){
    stack<char>st;
    string result;

    int n = s.length();

    for(int i=n-1;i>=0;i--){
        char ans = s[i];
        
        if((ans >= '0' && ans<='9') || (ans >= 'A' && ans <= 'Z') || (ans >= 'a' && ans <='z')){
            result += ans;
        }

        else if(ans == ')'){
            st.push(ans);
        }
        else if(ans == '('){
            while(st.top() != ')'){
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && value(ans) <= value(st.top()) ){
                result += st.top();
                st.pop();
            }
            st.push(ans);
        }
    }
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    stack<char>correct;
    int m = result.length();
    for(int j=0;j<m;j++){
        correct.push(result[j]);
    }
    for(int j=0; j<m ;j++){
        cout<<correct.top();
        correct.pop();
    }
}

int main(){
    string str = "(A-B/C)*(A/K-L)";
    convert(str);
}