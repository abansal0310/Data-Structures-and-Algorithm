#include<stdio.h>
#define max 30
int main()
{
int n, i, qt, count=0, temp, sq=0, bt[max], wt[max], tat[max], rem_bt[max], ct[max];
float awt = 0, atat= 0; 
printf("Enter the number of processes\n");
scanf("%d", &n);
printf("Enter the burst time of process\n");
for(i =0; i<n; i++)
{
    scanf("%d", &bt[i]);
    rem_bt[i] = bt[i];
}
printf("Enter quantum time");
scanf("%d", &qt);
while(1)
{
    for(i=0, count=0; i<n; i++)
{ 
    temp = qt;
    if(rem_bt[i]==0)
    {
        count++;
        continue;
    }
    if(rem_bt[i]>qt)
    rem_bt[i] = rem_bt[i]-qt;
    else
        if(rem_bt[i]>=0)
        {
        temp = rem_bt[i];
        rem_bt[i]=0;
        }
    sq = sq + temp;
    tat[i] = sq;
    ct[i]=tat[i];
}
    if(n==count)
    break;
}
printf("\nProcess\t burst time\t turnaraound time\t waiting time\t completion time\n");
 for(i = 0; i<n ;i++)
{
wt[i] = tat[i]-bt[i];
awt = awt+ wt[i];
atat = atat + tat[i];
printf("\n%d\\tt%d\t\t\t%d\t\t\t%d%d\t\t\t%d\n", i+1, bt[i], tat[i], wt[i],ct[i]);
}
awt = awt/n; 
atat = atat/n;
printf("Average waiting time = %f\n", awt);
printf("Average turnaround time = %f", atat);
return 0;
}