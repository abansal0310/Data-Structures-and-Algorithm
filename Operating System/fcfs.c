#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15],tat[15],wt[15];
    int ct[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
 
    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;
    }
 
    printf("Enter burst time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    ct[0]=bt[0];
    for(int i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
    }

    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i];
        wt[i]=tat[i]-bt[i];
    }

     printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float twt=0.0;
    float ttat= 0.0;
    for(int i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", tat[i]);
        printf("\n");

    }
}