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