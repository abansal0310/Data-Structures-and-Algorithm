#include<iostream>
using namespace std;

int eqmIndex(int arr[],int n){
    int lowSum=arr[0],highSum=arr[n];
    int k=n-2,l=1;
    for(int i=0;i<n;i++){
        if(lowSum>highSum){
            highSum+=arr[k];
            k--;
        }
        else if(lowSum<highSum){
            lowSum+=arr[l];
            l++;
        }
        else
            return k;
    }
    return -1;
}

int main(){
    int arr[]={-7, 1, 5, 2, -4, 3, 0};
    cout<<eqmIndex(arr,7)<<endl;

}