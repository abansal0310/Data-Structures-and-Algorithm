#include<iostream>
using namespace std;

//Naive Approach
int MaxSum(int arr[],int n,int x){
    int maxSum=0;
    for(int i=0;i<=n-x;i++){
        int sum=0;int k=i;
        for(int j=0;j<x;j++){
            sum = sum+arr[k];
            k++;
        }
        maxSum = max(sum,maxSum);
    }
    return maxSum;
}

int main(){
    int arr[]={1, 4, 2, 10, 23, 3, 1, 0, 20};
    cout<<MaxSum(arr,9,4)<<endl;
}