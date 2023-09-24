#include<iostream>
#include<string>
#include<stack>

using namespace std;

void reverseWord(string str){
    int n = str.length();
    stack<char>temp;
    string ans;
    for(int i=0;i<n;i++){
        char c = str[i];
        if((c >= 'a'&& c<= 'z')||(c>= 'A' && c <= 'Z')){
            temp.push(c);
        }
        else{
            while(!temp.empty()){
                ans+=temp.top();
                temp.pop();
            }
            ans+=" ";
        }
    }
    while(!temp.empty()){
        ans+=temp.top();
        temp.pop();
    }

    cout<<ans<<endl;
}

int main(){
    string st = "pratham is good boy";
    reverseWord(st);
}