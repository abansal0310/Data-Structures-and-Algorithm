#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void selectSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int Short = i;
        for(int j=i+1;j<n;j++){
            if(arr[Short]>arr[j])
                Short=j;
        }
        swap(arr[i],arr[Short]);
    }
}

int main(){
    int arr[]={6,4,2,3,1};
    selectSort(arr,5);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}