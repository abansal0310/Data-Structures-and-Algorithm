#include<iostream>
using namespace std;
//@abansal0310

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        bool temp=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(temp==false)
            break;
    }
}

int main(){
    int arr[10]={2,3,6,1,8,9,4,7,5};
    bubbleSort(arr,9);
    for(int i=0;i<9;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}