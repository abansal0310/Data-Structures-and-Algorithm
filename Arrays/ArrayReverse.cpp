#include<iostream>
using namespace std;

void swap(int *arr1,int *arr2){
    int temp;
    temp=*arr1;
    *arr1=*arr2;
    *arr2=temp;
}

void arrayReverse(int arr[],int n){
    for(int i=0; i<n/2; i++){
        swap(arr[i],arr[n-1-i]);
    }
}

int recursionReverse(int arr[],int low,int high){
    if(low>=high){
        return 0 ;
    }
    else{
        swap(arr[low],arr[high]);
        recursionReverse(arr,low+1,high-1);
    }
}


void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[5]={1,2,3,4,5};
    arrayReverse(arr,5);
    print(arr,5);
    recursionReverse(arr,0,4);
    print(arr,5);
}