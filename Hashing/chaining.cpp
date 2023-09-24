#include<iostream>
#include<list>
using namespace std;

struct myHash{
    int bucket;
    list<int>*table;
    myHash(int x){
        bucket = x;
        table = new list<int>[x];
    }
    void insert(int key);
    void search(int key);
    void remove(int key);
};

void myHash::insert(int key){
    int i = key%bucket;
    table[i].push_back(key);
}

void myHash::search(int key){
    int i = key%bucket;
    for(auto n:table[i]){
        if(key==i){

        }
    }
}

int main(){
	
}
