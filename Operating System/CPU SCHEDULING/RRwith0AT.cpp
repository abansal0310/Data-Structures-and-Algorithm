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
