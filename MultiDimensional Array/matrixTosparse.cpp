#include<iostream>
using namespace std;

struct element{
    int i,j,x;
    element(int a=0, int b=0, int c=0){
        i=a;
        j=b;
        x=c;
    }
};

struct matrix{
    int row,column,e;
    element *ele;
    matrix(int a, int b, int c){
        row=a;
        column=b;
        e=c;
        ele = new element(e);
    }

    ~matrix(){
        delete [] ele;
    }

    void read(){
        for(int a=0;a<e;a++){
            
        }
    }


};

int main();