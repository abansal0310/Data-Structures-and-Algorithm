#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

int evaluation(char *s){
    stack<int>ans;

    for(int i=0;s[i];++i){
        if(isdigit(s[i])){
            ans.push(s[i]-'0');
        }
        else{
            int val1 = ans.top();   
            ans.pop();
            int val2 = ans.top(); 
            ans.pop();

            switch(s[i]){
                case '+' : ans.push(val1+val2); break;
                case '-' : ans.push(val1-val2); break;
                case '*' : ans.push(val1*val2); break;
                case '/' : ans.push(val1/val2); break;
            }
        }
    }
    return ans.top();
}

int main(){
    char exp[] = "231*+9-"; 
    cout<<"postfix evaluation: "<< evaluation(exp); 
    return 0; 
}