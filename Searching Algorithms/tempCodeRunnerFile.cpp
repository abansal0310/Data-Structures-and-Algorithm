#include<iostream>
using namespace std;

void swap(int*a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

void sort(int arr[],int n){
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                flag=true;
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void repeating(int arr[],int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]==arr[i+1]){
            cout<<"Repeating Element : "<<arr[i]<<endl;
        }
    }
}

void missing(int arr[],int n){
    int k=1;
    for(int i=0;i<n;i++){
        if(arr[i]>k){
            cout<<"Missing Element : "<<k<<endl;
            k++;
        }
        k++;
    }
}

int main(){
    int arr[10]={1,2,5,7,9,7,6,5,8};
    sort(arr,9);
    repeating(arr,9);
    missing(arr,9);
    
}