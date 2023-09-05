#include<iostream>
using namespace std;

int largestElement(int arr[],int n){
    int large=0;
    for(int i=0;i<n;i++){
        if(large<arr[i]){
            large=arr[i];
        }
    }
    return large;
}

int main(){
    int arr[]={20,10,20,4,100};
    cout<<"Largest Element : "<<largestElement(arr,5)<<endl;
}
