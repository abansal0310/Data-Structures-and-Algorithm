//CPU SCHEDULING
//FCFS


#include <iostream>
using namespace std;
int main()
{
    // n stores the number of processes
    int n = 5;

    int process[] = {1, 2, 3, 4, 5};
    int arrival_time[] = {2, 5, 1, 0, 4};
    int burst_time[] = {6, 2, 8, 3, 4};
    int tat[] = {0, 0, 0, 0, 0};
    int waiting_time[] = {0, 0, 0, 0, 0};
    int exit_time[] = {0, 0, 0, 0, 0};

    // Sorting all the processes according to the arrival times
    // As FCFS is based on the arrival time of different processes

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                swap(process[j], process[j + 1]);
                swap(arrival_time[j], arrival_time[j + 1]);
                swap(burst_time[j], burst_time[j + 1]);
            }
        }
    }

    // Order of Execution
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << " ";
    }
    cout << endl;

    // Time counteto keep track of the total time
    int time = 0;

    for (int i = 0; i < n; i++)
    {
        // Check if for eg the time is 4 and next process arrives at 9 so we need to update time from 4 to 9
        if (time < arrival_time[i])
        {
            time = arrival_time[i];
        }

        // ExitTime
        exit_time[i] = time + burst_time[i];

        // Updating the time variable
        time = time + burst_time[i];
    }

    // Calculating the TurnAroundTime and Waiting Time
    for (int i = 0; i < n; i++)
    {
        tat[i] = exit_time[i] - arrival_time[i];
        waiting_time[i] = tat[i] - burst_time[i];
    }

    // Printing all the data
    cout << "P"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "WT"
         << "\t"
         << "TAT"
         << "\t"
         << "ExitT" << endl;
         for (int i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << arrival_time[i] << "\t" << burst_time[i] << "\t" << waiting_time[i] << "\t" << tat[i] << "\t" << exit_time[i] << endl;
    }

    return 0;
}


















//RR with 0AT
// Round Robin program where the arrival time for all the processes is 0
#include <iostream>
using namespace std;
int main()
{
    int n = 3;
    int BT[] = {10, 5, 8};
    int RBT[] = {10, 5, 8};
    int CT[3];
    int WT[3];
    int quantum = 2;
    int time = 0;
    while (true)
    {
        bool flag_completed = true;
        for (int i = 0; i < n; i++)
        {
            if (RBT[i] > 0)
            {
                flag_completed = false;
                if (RBT[i] > quantum)
                {
                    RBT[i] = RBT[i] - quantum;
                    time = time + quantum;
                }
                else
                {
                    time = time + RBT[i];
                    CT[i]=time;
                    WT[i] = time - BT[i];
                    RBT[i] = 0;
                }
            }
        }
        if (flag_completed == true)
        {
            break;
        }
    }

    cout << "P"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "WT"
         << "\t"
         << "ExitT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << "\t" << 0 << "\t" << BT[i] << "\t" << WT[i] << "\t" << CT[i] << endl;
    }
    return 0;
}
































//ROUND ROBBIN
#include <iostream>
// Using the inbuid queues in C++
#include <queue>
using namespace std;

// Function to check whether all the processes have executed or not
bool check(bool arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    // Initializing a Queue to be used as the ready queue of RR
    queue<int> rq;

    // n=Total number of processes
    int n = 6;

    int process[] = {1, 2, 3, 4, 5, 6};

    int process_index[n]; // Stores the index of a process
    for (int i = 0; i < n; i++)
    {
        process_index[i] = process[i] - 1;
    }

    int arrival_time[] = {0, 1, 2, 3, 4, 6};
    int burst_time[] = {5, 6, 3, 1, 5, 4};

    // Burst Time Original is to be used for calculating WT at the end
    int burst_time_original[] = {5, 6, 3, 1, 5, 4};

    // Sorting the given process according to their arrival time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                swap(process[j], process[j + 1]);
                swap(process_index[j], process_index[j + 1]);
                swap(arrival_time[j], arrival_time[j + 1]);
                swap(burst_time[j], burst_time[j + 1]);
                swap(burst_time_original[j], burst_time_original[j + 1]);
            }
        }
    }

    int tat[] = {0, 0, 0, 0, 0, 0};
    int waiting_time[] = {0, 0, 0, 0, 0, 0};
    int exit_time[] = {0, 0, 0, 0, 0, 0};

    // is_complete array keeps record of whether the process has completed or not
    bool is_completed[] = {false, false, false, false, false, false};

    // q stores the time Quantum
    int q = 4;

    // Variable running stores the index of the process that is currently executing
    int running = process_index[0];

    // time variable keeps record of the time
    int time = arrival_time[0];

    // break_time increases by q everytime a process ends or a time quantum ends
    // Note break_time is necessary because for eg: If q=2 and BT=1 then the new process will run from 1-3 and not 1-2
    int break_time = q;

    while (!check(is_completed, n)) // Executing till all the process have not completed
    {
        --burst_time[running];
        ++time;

        // Checking and adding to the ready queue if a process has arrivesd at this time
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] == time)
            {
                rq.push(process_index[i]);
            }
        }

        // Process switching condition
        if (burst_time[running] == 0 || time == break_time)
        {
            if (burst_time[running] == 0)
            {
                is_completed[running] = true;
                exit_time[running] = time;
            }
            else
            {
                // If the process is incomplete, it is pushed back into the ready queue
                rq.push(running);
            }

            // front() gets first element of the queue and pop() removes it from the queue
            running = rq.front();
            rq.pop();

            break_time = time + q;
        }
    }

    // Calculating the TurnAroundTime and Waiting Time
    for (int i = 0; i < n; i++)
    {
        tat[i] = exit_time[i] - arrival_time[i];
        waiting_time[i] = tat[i] - burst_time_original[i];
    }

    // Printing all the data
    cout << "P"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "WT"
         << "\t"
         << "TAT"
         << "\t"
         << "ExitT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << arrival_time[i] << "\t" << burst_time_original[i] << "\t" << waiting_time[i] << "\t" << tat[i] << "\t" << exit_time[i] << endl;
    }
    return 0;
}

//To check for different examples change the data of the required fields























//SJF
#include <iostream>
using namespace std;

// Returns the index of the process with the minimum burst time
int minimumBT(int BT[], int n)
{
    int min = 10000;
    int min_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (BT[i] > 0 && BT[i] < min)
        {
            min = BT[i];
            min_index = i;
        }
    }
    return min_index;
}

// Returns true if all the processes have executed else returns false
bool check(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            return false;
        }
    }
    return true;
}

// Driver Main
int main()
{
    int n = 5;
    int process[] = {1, 2, 3, 4, 5};
    int arrival_time[] = {2, 5, 1, 0, 4};
    int burst_time[] = {6, 2, 8, 3, 4};
    int burst_time_original[] = {6, 2, 8, 3, 4};

    int is_complete[] = {0, 0, 0, 0, 0}; // To keep track of the completed processes

    int tat[] = {0, 0, 0, 0, 0};
    int waiting_time[] = {0, 0, 0, 0, 0};
    int exit_time[] = {0, 0, 0, 0, 0};

    // Sorting all the processes according to the arrival times
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                swap(process[j], process[j + 1]);
                swap(arrival_time[j], arrival_time[j + 1]);
                swap(burst_time[j], burst_time[j + 1]);
                swap(burst_time_original[j], burst_time_original[j + 1]);
            }
        }
    }

    // Time variable to keep track of the time
    int time = arrival_time[0];
    while (!check(is_complete, n))
    {
        int j = 0;
        // Checking how many process have arrival time <= current time and then setting the j pointer accordingly
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time)
            {
                j++;
            }
        }

        // Running the task with the minimum BT
        int running = minimumBT(burst_time, j);

        // Updating the time variable
        time = time + burst_time[running];

        burst_time[running] = 0;
        is_complete[running] = 1;

        exit_time[running] = time;
    }

    // Calculating the TurnAroundTime and Waiting Time for (int i = 0; i < n; i++)
    for (int i = 0; i < n; i++)
    {
        tat[i] = exit_time[i] - arrival_time[i];
        waiting_time[i] = tat[i] - burst_time_original[i];
    }

    // Printing all the data
    cout << "P"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "WT"
         << "\t"
         << "TAT"
         << "\t"
         << "ExitT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << arrival_time[i] << "\t" << burst_time_original[i] << "\t" << waiting_time[i] << "\t" << tat[i] << "\t" << exit_time[i] << endl;
    }
    return 0;
}


















//SRTF
#include <iostream>
using namespace std;

// Returns the index of the process with the minimum burst time
int minimumBT(int BT[], int n)
{
    int min = 10000;
    int min_index = -1;
    for (int i = 0; i < n; i++)
    {
        if (BT[i] > 0 && BT[i] < min)
        {
            min = BT[i];
            min_index = i;
        }
    }
    return min_index;
}

// Returns true if all the processes have executed else returns false
bool check(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 5;
    int process[] = {1, 2, 3, 4, 5};
    int arrival_time[] = {2, 5, 1, 0, 4};
    int burst_time[] = {6, 2, 8, 3, 4};
    int burst_time_original[] = {6, 2, 8, 3, 4};

    // To keep track of the completed processes
    int is_complete[] = {0, 0, 0, 0, 0};
    int tat[] = {0, 0, 0, 0, 0};
    int waiting_time[] = {0, 0, 0, 0, 0};
    int exit_time[] = {0, 0, 0, 0, 0};

    // Sorting all the processes according to the arrival times
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival_time[j] > arrival_time[j + 1])
            {
                swap(process[j], process[j + 1]);
                swap(arrival_time[j], arrival_time[j + 1]);
                swap(burst_time[j], burst_time[j + 1]);
                swap(burst_time_original[j], burst_time_original[j + 1]);
            }
        }
    }

    int time = 0;
    while (!check(is_complete, n))
    {
        int j = 0;

        // Checking how many process have arrival time <= current time and then setting the j pointer accordingly
        for (int i = 0; i < n; i++)
        {
            if (arrival_time[i] <= time)
            {
                j++;
            }
        }

        // Running the task with the minimum BT
        int running = minimumBT(burst_time, j);

        // Updating the time variable and reducing the time variable by 1
        ++time;
        --burst_time[running];

        // Check for the process completion
        if (burst_time[running] == 0)
        {
            is_complete[running] = 1;
            exit_time[running] = time;
        }
    }

    // Calculating the TurnAroundTime and Waiting Time for (int i = 0; i < n; i++)
    for (int i = 0; i < n; i++)
    {
        tat[i] = exit_time[i] - arrival_time[i];
        waiting_time[i] = tat[i] - burst_time_original[i];
    }

    // Printing all the data
    cout << "P"
         << "\t"
         << "AT"
         << "\t"
         << "BT"
         << "\t"
         << "WT"
         << "\t"
         << "TAT"
         << "\t"
         << "ExitT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << process[i] << "\t" << arrival_time[i] << "\t" << burst_time_original[i] << "\t" << waiting_time[i] << "\t" << tat[i] << "\t" << exit_time[i] << endl;
    }
    return 0;

    return 0;
}
















































//DISK SCHEDULING
//CSCAN
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





























//FCFS
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


































//SCAN
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










































//SSTF
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








































//BANKER ALGORITM
#include <iostream>
using namespace std;

int main()
{
    int n = 5; // Number of processes
    int m = 3; // Number of resources

    // Allocation Matrix
    int alloc[5][3] = {{0, 1, 0},  // P0
                       {2, 0, 0},  // P1
                       {3, 0, 2},  // P2
                       {2, 1, 1},  // P3
                       {0, 0, 2}}; // P4

    // MAX Matrix
    int max[5][3] = {{7, 5, 3},  // P0
                     {3, 2, 2},  // P1
                     {9, 0, 2},  // P2
                     {2, 2, 2},  // P3
                     {4, 3, 3}}; // P4

    // Available Resources
    int avail[3] = {3, 3, 2};

    int finished[n] = {0, 0, 0, 0, 0};//To keep track of the allocated processes

    int ans[n];  // Stores the final safe sequence
    int ind = 0; // Global index for the ans matrix

    // Need=Max-Allocation
    int need[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < n; i++)
        {
            // If the process has not finished
            if (finished[i] == 0)
            {
                // flag value 0 indicates that need < available ==> resource will be allocated
                int flag = 0;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] = avail[y] + alloc[i][y];
                    finished[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++)
    {
        if (finished[i] == 0)
        {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    if (flag == 1)
    {
        cout << "Following is the SAFE Sequence" << endl;
        for (int i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl;
    }

    return (0);
}







































//MEMORY MANAGEMENT
//BEST FIT
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











































//FIRST FIT
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













































//WORST FIT
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
