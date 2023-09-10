#include<iostream>
using namespace std;

void partition(int arr[],int n){
    int low=0,high=n-1;
    int mid=(low+high)/2;

    int temp[n];int k=0;
    for(int i=0;i<n;i++){
        if(arr[i]<arr[mid])
            temp[k]=arr[i];
            k++;
    }
    for(int i=0;i<n;i++ ){
        
    }
}


int main(){

}