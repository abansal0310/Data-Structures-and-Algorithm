#include<iostream>
using namespace std;
//@abansal0310

void insertSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i;
        while(arr[j-1]>temp && j>=0){
            arr[j]=arr[j-1];
            j--;
        }
    arr[j]=temp;
    }
}

int main(){
    int arr[]={6,4,2,3,1};
    insertSort(arr,5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}