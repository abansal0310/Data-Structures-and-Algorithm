
#include <iostream>

using namespace std;

struct Tree
{
    int arr[7];
    // int level;
    int size;

    int ptrL;
    int ptrR;

    Tree(int x)
    {
        size = x;
        ptrL = 1;
        ptrR = 2;
    }

    void insertLeft(int a);
    void insertRight(int b);
    void print();
};

void Tree::insertLeft(int a)
{
    arr[ptrL] = a;
    ptrL = ptrL + 2;
    arr[ptrL] = '\0';
}

void Tree::insertRight(int b)
{
    arr[ptrR] = b;
    ptrR = ptrR + 2;
    arr[ptrR] = '\0';
}

void Tree::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Tree t1(7);
    t1.arr[0] = 5;
    t1.insertLeft(10);
    t1.insertRight(20);
    t1.insertLeft(30);
    t1.insertRight(40);
    t1.insertRight(50);

    t1.print();
}
