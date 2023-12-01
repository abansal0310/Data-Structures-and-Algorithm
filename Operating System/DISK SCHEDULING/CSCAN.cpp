// Given the seek direction is from left to right
// Given right most pointer of the disk is 199
#include <iostream>
using namespace std;
int main()
{
    int p = 8;
    int request[p] = {176, 79, 34, 60, 92, 11, 41, 114};

    int head = 50;
    int head_original = 50;

    int end_index = 199;

    cout << "Sequence: " << endl;
    cout << head << " ";

    for (int i = 0; i < p + 1; i++)
    {
        // Finding the index of the request with the minimum distance ahead of the head variable
        int min_distance = 10000;
        int min_index;
        for (int j = 0; j < p; j++)
        {
            if (request[j] > head && (request[j] - head) < min_distance) // Checking the 2 conditions
            {
                min_distance = request[j] - head;
                min_index = j;
            }
        }
        // min_distance==10000 implies that there is no other request greater than the head, so head will go to end index and then
        // start from the beginning in a circular manner
        if (min_distance == 10000)
        {
            head = end_index;
            cout << head << " ";
            head = 0;
            cout << head << " ";
        }
        else
        {
            head = request[min_index];
            cout << head << " ";
        }
    }
    // Printing the head variable in corresponding steps gives us the Seek Sequence
    cout << "\nSeek Count " << (end_index - head_original + end_index + head);

    return 0;
}