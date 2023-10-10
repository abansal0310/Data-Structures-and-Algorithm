#include<iostream>
#include<queue>
using namespace std;

struct Queue{
    queue<int>q1;
    queue<int>q2;
    void insert(int x){
        
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop(); 
        }
    }
};

int main(){

}