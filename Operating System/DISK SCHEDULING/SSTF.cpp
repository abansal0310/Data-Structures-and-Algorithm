#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    int request[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int request_granted[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int head = 50;

    int sequence[n + 1];
    sequence[0] = head;
    int sequence_index = 1;

    int seek_count = 0;
    for (int i = 0; i < n; i++)
    {
        int min_distance = 10000;
        int min_dist_index;
        for (int j = 0; j < n; j++)
        {
            int distance = abs(request[j] - head);
            if (distance < min_distance && request_granted[j] == 0)
            {
                min_distance = distance;
                min_dist_index = j;
            }
        }
        seek_count = seek_count + min_distance;
        head = request[min_dist_index];
        request_granted[min_dist_index] = 1;
        sequence[sequence_index++] = request[min_dist_index];
    }

    cout << "SeekCount: " << seek_count << endl;
    cout << "SeekSequence:-" << endl;
    for (int i = 0; i < n + 1; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}