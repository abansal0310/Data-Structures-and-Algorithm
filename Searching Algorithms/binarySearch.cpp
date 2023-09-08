#include<iostream>
using namespace std;

int bsearchh(int arr[],int n,int x){
    int high=n-1;int low =0;
    while(high>=low){
        int mid=(high+low)/2;
        if(arr[mid]>x)
            high=mid-1;
        else if(arr[mid]<x)
            low=mid+1;
        else
            return mid;
    }
    return -1;
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9};

    cout<<bsearchh(arr,9,5);
}