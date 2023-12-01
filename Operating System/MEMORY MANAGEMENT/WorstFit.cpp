#include <iostream>
using namespace std;
int main()
{
    int n = 4; // No of processes
    int m = 5; // No of memory blocks

    int Process_size[] = {212, 417, 112, 426};
    int Memory_block_size[] = {100, 500, 200, 300, 600};

    int allocation[n]; // To store the alloted memory block for a particular process

    for (int i = 0; i < n; i++)
    {
        // Calculating the maximum available memory block that can accomodate the process
        int max = -1;
        int max_index;
        for (int j = 0; j < m; j++)
        {
            if (Process_size[i] < Memory_block_size[j] && Memory_block_size[j] > max)
            {
                max = Memory_block_size[j];
                max_index = j;
            }
        }
        // max value is unchanged implies that the process cannot be accomodated in any available memory block
        if (max == -1)
            allocation[i] = -1;
        else
        {
            Memory_block_size[max_index] = Memory_block_size[max_index] - Process_size[i];
            allocation[i] = max_index + 1; //+1 to convert index to process number
        }
    }

    // Printing the final result
    cout << "Process\t"
         << "Process Size\t"
         << "Block No." << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << "\t" << Process_size[i] << "\t";

        // Check for the not allotted case
        if (allocation[i] == -1)
            cout << "Not Allotted" << endl;
        else
            cout << allocation[i] << endl;
    }
    return 0;
}