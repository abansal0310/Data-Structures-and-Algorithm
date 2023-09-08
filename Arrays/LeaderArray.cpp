#include<iostream>
#include<vector>
using namespace std;

vector<int>Leader(int arr[],int n){
    vector<int>s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[n-1]){
                s.push_back(arr[i]);
            }
            else{
                if(arr[i]<arr[j]){
                    
                }
            }
        }
    }
}

int main(){

}