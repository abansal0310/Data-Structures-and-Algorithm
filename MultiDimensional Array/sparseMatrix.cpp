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
    int row,column,ele;
    element *e;

    matrix(int a, int b, int c){
        row=a;
        column=b;
        ele=c;
        e = new struct element(ele);
    }

    ~matrix(){
        delete [] e;
    }

    void read(){
        cout<<"Enter non-zero Elements"<<endl;
        for(int a=0;a<ele;a++){
            cin>>e[a].i>>e[a].j>>e[a].x;
        }
    }

    void display(){
        int k=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                if(e[k].i==i && e[k].j ==j ){
                    cout<<e[k++].x<<" ";
                }
                else
                    cout<<"0 ";
            }
            cout<<endl;
        }
    }

    matrix operator+(matrix &s){
        int i,j,k;
        if(row != s.row || column != s.column)
            return ;
        matrix *sum = new matrix(row,column,ele+s.ele);
        i=j=k=0;
        while(i<ele && j<s.ele){
            
        }

    }
};



int main(){
    matrix m2(5,5,5);
    m2.read();
    m2.display();
}