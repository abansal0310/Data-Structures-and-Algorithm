#include <iostream>
using namespace std;

struct Heap
{
    int arr[5] = {4, 10, 3, 5, 1};
    int size, capacity;
    Heap(int x)
    {
        // int arr[x];
        size = x;
        capacity = 0;
    }

    int parent(int i) { return ((i - 1) / 2); }
    int left(int i) { return ((2 * i) + 1); }
    int right(int i) { return (2 * i + 2); }

    void HeapSort();
};

void Heap::HeapSort()
{
    int i = 0;
    for (int i = 0; i < size && arr[left(i)] > arr[i] || arr[right(i)] > arr[i];)
    {
        int minElement = min(arr[left(i)], arr[right(i)]);
        swap(minElement, arr[i]);
        i = parent(i);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Heap h(5);
    h.HeapSort();
}