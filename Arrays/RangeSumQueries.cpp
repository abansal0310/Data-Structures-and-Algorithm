#include<iostream>
using namespace std;

int sumRange(int arr[],int low, int high, int n){
    if(low<0 || high>n){
        return -1;
    }
    int sum=0;
    for(int i=low;i<=high;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){
    int arr[]={4, 5, 3, 2, 5};
    cout<<sumRange(arr,0,3,5)<<endl;
}