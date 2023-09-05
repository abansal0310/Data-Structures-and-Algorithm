#include<iostream>
#include<vector>
using namespace std;

vector<int>merge(int arr1[],int arr2[],int m, int n){
    vector<int>s;
    int i=0,j=0;
    while(i<m && j<n){
        if(arr1[i]>arr2[j]){
            s.push_back(arr2[j]);
            j++;
        }
        else if(arr1[i]<arr2[j]){
            s.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]==arr2[j]){
            s.push_back(arr1[i]);
            i++;j++; 
        }
        
    }
    while(i<m){
        s.push_back(arr1[i]);
        i++; 
    }
    while(j<n){
        s.push_back(arr2[j]);
        j++; 
    }

    return s;
}

int main(){
    int arr1[]={1,3,4,6};
    int arr2[]={2,5,7,8};

    vector<int>a;
    a=merge(arr1,arr2,4,4);
    for (auto i = a.begin(); i != a.end(); ++i) 
        cout << *i << " ";
}