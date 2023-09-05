#include<iostream>
using namespace std;

//Kaldane's Algorithim

int largestSum(int arr[],int n){
    int sum=0,maxSum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        maxSum=max(maxSum,sum);

        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}

int main(){
    int arr[]={-3, 4, -1, -2, 1, 5};
    cout<<largestSum(arr,6)<<endl;
}