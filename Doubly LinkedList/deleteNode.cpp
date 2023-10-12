#include<iostream>
using namespace std;

struct Node{
    Node *next;
    Node *prev;
    int data;
    Node(int x){
        data = x;
        prev=next=NULL;
    }
};



int main(){

}