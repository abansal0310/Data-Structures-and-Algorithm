#include<iostream>
using namespace std;

int main(){
    int arr[3][4]={{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};
    for(int row=0;row<4;row++){
        if(row%2==0){
            for(int col=0;col<3;col++){
                cout<<arr[col][row]<<" ";
            }
        }
        else{
            for(int col=2;col>=0;col--){
                cout<<arr[col][row]<<" ";
            }
        }
    }
}