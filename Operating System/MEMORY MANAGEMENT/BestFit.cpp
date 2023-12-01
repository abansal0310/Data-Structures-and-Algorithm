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
        // Calculating the minimum available memory block that can accomodate the process
        int min = 1000000;
        int min_index;
        for (int j = 0; j < m; j++)
        {
            if (Process_size[i] < Memory_block_size[j] && Memory_block_size[j] < min)
            {
                min = Memory_block_size[j];
                min_index = j;
            }
        }
        // min value is unchanged implies that the process cannot be accomodated in any available memory block
        if (min == 1000000)
            allocation[i] = -1;
        else
        {
            Memory_block_size[min_index] = Memory_block_size[min_index] - Process_size[i];
            allocation[i] = min_index + 1; //+1 to convert index to process number
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