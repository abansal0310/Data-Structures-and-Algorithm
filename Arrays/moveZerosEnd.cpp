#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void moveZeros(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-1;j++){
            if(arr[j]==0){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void MoveZeros(int arr[],int n){
    int count=0;int k=0;
    int temp[n];
    // for(int i=0;i<n;i++){
    //     if(arr[i]==0)
    //         count++;
    // }
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp[k]=arr[i];
            k++;
        }
    }
    for(int i=k;i<n;i++){
        temp[i]=0;
    }
    print(temp,n);
    
}



int main(){
    int arr[]={1,0,2,3,0,0,4,0,5};
    // moveZeros(arr,9);
    // print(arr,9);
    MoveZeros(arr,9);
}