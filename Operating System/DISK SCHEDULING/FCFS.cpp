#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    int request[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int head = 50;

    int sequence[n + 1];
    sequence[0] = head;
    int sequence_index = 1;

    int seek_count = 0;
    for (int i = 0; i < n; i++)
    {
        seek_count = seek_count + abs(request[i] - head);
        head = request[i];
        sequence[sequence_index++] = request[i];
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