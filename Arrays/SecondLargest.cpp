#include<iostream>
using namespace std;

int largest(int arr[],int n){
    int large=0;
    for(int i=0;i<n;i++){
        if(large<arr[i]){
            large=arr[i];
        }
    }
    return large;
}

int secLarge(int arr[],int n){
    int secLarge=0;
    for(int i=0;i<n;i++){
        if(arr[i]>secLarge && arr[i]!=largest(arr,n)){
            secLarge=arr[i];
        }
    }
    return secLarge;
}

int main(){
    int arr[]={12, 35, 1, 10, 34, 1};
    cout<<"Second Largest : "<<secLarge(arr,6)<<endl;
}