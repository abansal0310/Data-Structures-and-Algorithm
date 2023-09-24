#include <iostream>
using namespace std;

/*Input : abc
Output : a, b, c, ab, bc, ac, abc*/

int main(){
    string str = "akshit";
    for(int i=0;i<str.length();i++){
        char out = str[i];
        for(int j=i+1;j<str.length();j++){
            cout<<(out + str[j])<<endl;
        }
    }
}