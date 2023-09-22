#include<iostream>
using namespace std;

void sortEvenOdd(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]%2==0){
            cout<<arr[i]<<" ";
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2 != 0){
            cout<<arr[i]<<" ";
        }
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}

void efficientSort(int arr[], int n){
    int i=0,j=1;
    while(i<n && j<n){
        if(arr[i]%2 !=0 ){
            if(arr[j]%2 ==0){
                swap(arr[i],arr[j]);i=i+2;j=j+2;
            }
            else
                i=i+2;}
        else
            j=j+2;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    //sortEvenOdd(arr,10);
    efficientSort(arr,10);
}