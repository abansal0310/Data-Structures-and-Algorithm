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

    // Time counter to keep track of the total time
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