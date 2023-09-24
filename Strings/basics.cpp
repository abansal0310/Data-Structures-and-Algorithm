#include<iostream>
#include<string>
using namespace std;

int main(){
    //Acessing Characters by Index
    string test = "Pratham is a good Boy";
    cout<<"Char at 4 : "<<test[4]<<endl;
    test.insert(5,"a");
    cout<<test<<endl;

    //Iteratiion in Strings
    for(int i=0;i<test.length();i++){
        cout<<test[i]<<" ";
    }
    
}