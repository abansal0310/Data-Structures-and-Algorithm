#include <iostream>
using namespace std;
int main()
{
    int n = 4; // Number of processes
    int m = 5; // Number of memory Blocks
    int Process_size[] = {212, 417, 112, 426};
    int Memory_block_size[] = {100, 500, 200, 300, 600};
    int allocation[n]; // To store the alloted memory block for a particular process

    for (int i = 0; i < n; i++)
    {
        // flag is used to keep a check if non of the available resource can accomodate the process
        int flag = 0;
        for (int j = 0; j < 5; j++)
        {
            if (Process_size[i] <= Memory_block_size[j])
            {
                allocation[i] = j + 1; //+1 for 1 as j stores only the index

                Memory_block_size[j] = Memory_block_size[j] - Process_size[i];

                flag = 1;
                break;
            }
        }
        // flag=0 implies no memory block can accomodate the process
        if (flag == 0)
        {
            allocation[i] = -1;
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