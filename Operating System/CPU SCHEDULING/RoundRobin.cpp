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