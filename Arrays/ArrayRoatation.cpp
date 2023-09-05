#include<iostream>
using namespace std;

void ArrayRotation(int arr[],int n, int d){
    int i,j;
    for(i=1;i<=d;i++){
        int temp = arr[0];
        for(j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[j]=temp;
    }
}

void arrayRotation(int arr[],int n, int d){
    int temp[d];int k=0;int i;
    for(i=0;i<d;i++){
         temp[i]=arr[i];
    }
    i=0;
    for(int j=d;j<n;j++){
        arr[i]=arr[j];
        i++;
    }
    for(int j=d-1;j<n;j++){
        arr[j]=temp[k];
        k++;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    ArrayRotation(arr,5,2);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    arrayRotation(arr,5,3);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}