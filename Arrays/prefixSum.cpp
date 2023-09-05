#include<iostream>
using namespace std;

void PrefixSum(int arr[],int n){
    int elementSum=0;
    for(int i=0;i<n;i++){
        elementSum+=arr[i];
        arr[i]=elementSum;
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[]={10, 20, 10, 5, 15};
    PrefixSum(arr,5);
    print(arr,5);
}