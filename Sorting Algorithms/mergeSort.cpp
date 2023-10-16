#include<iostream>
using namespace std;
//@abansal0310

void mergeArray(int arr1[], int arr2[], int n, int m){
    int temp[m+n];
    int i=0,j=0,k=0;

    while(i<n && j<m){
        if(arr1[i]>arr2[j]){
            temp[k]=arr2[j];
            j++;k++;
        }

        else if(arr1[i]<arr2[j]){
            temp[k]=arr1[i];
            i++;k++;
        }

        else{
            temp[k]=arr1[i];
            i++;j++;k++;
        }
    }

    while(i<n){
        temp[k]=arr1[i];
        i++;k++;
    }

    while(j<m){
        temp[k]=arr2[j];
        j++;k++;
    }
    
}



int main(){

}

