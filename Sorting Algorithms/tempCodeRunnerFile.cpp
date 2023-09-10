#include<iostream>
using namespace std;

void insertSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i;
        while(arr[j-1]>temp && j>=0){
            arr[j-1]=arr[j];
            j--;
        }
    arr[i]=temp;
    }
}

int main(){
    int arr[]={6,4,2,1,3};
    insertSort(arr,5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}