#include<iostream>
using namespace std;

void makeArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<"Enter the Element : ";
        cin>>arr[i];
        cout<<endl;
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertArray(int arr[], int n, int pos, int ele){
    for(int i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=ele;
}

void deleteArray(int arr[], int n, int pos){
    for(int i= pos; i<n;i++){
        arr[i]=arr[i+1];
    }
}

int main(){
    int arr[10];
    makeArray(arr,5);
    printArray(arr,5);

    insertArray(arr,6,3,68);
    printArray(arr,6); 

    deleteArray(arr,6,3);
    printArray(arr,5);
}