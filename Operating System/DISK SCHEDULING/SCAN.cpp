//Given the seek direction is from right to left
#include <iostream>
using namespace std;
int main()
{
    int p = 8;
    int request[p] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    int n = p + 1;
    int sequence[n];
    // Adding head to the sequence
    sequence[0] = head;

    // Copying the reqeuest array to the sequence array
    for (int i = 1; i < n; i++)
    {
        sequence[i] = request[i - 1];
    }

    // Sorting the entire sequence in ascending order using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sequence[j] > sequence[j + 1])
            {
                swap(sequence[j], sequence[j + 1]);
            }
        }
    }

    // Finding the index of head
    int head_index;
    for (int i = 0; i < n; i++)
    {
        if (sequence[i] == head)
        {
            head_index = i;
            break;
        }
    }

    // sorting the sequece array till head in reverse order
    for (int i = 0; i < head_index - 1; i++)
    {
        for (int j = 0; j < head_index - i - 1; j++)
        {
            if (sequence[j] < sequence[j + 1])
            {
                swap(sequence[j], sequence[j + 1]);
            }
        }
    }

    // Note the formula of the seek_count will be adjusted according to the direction given in the question
    int seek_count = head + sequence[n - 1];
    cout << "SeekCount: " << seek_count << endl;

    // Printing the sequence
    cout << "SeekSequence:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}