#include<iostream>
#include<vector>
using namespace std;

//Array is Sorted
void remDuplicate(int arr[],int n){
    int temp[n];
    temp[0]=arr[0];
    int k=0;
    for(int i=0;i<n;i++){
        if(temp[k] != arr[i]){
            temp[k]=arr[i];
            k++;
        }
    }

    for(int i=0;i<k;i++){
        cout<<temp[i]<<" ";
    }
}

int main(){
    int arr[]={1, 2, 2, 3, 4, 4, 4, 5, 5};
    remDuplicate(arr,9);
}