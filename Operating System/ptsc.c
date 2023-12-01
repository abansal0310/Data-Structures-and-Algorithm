#include <stdio.h>
int main()
{
    int p[15],at[15],temp,pt[15];
    int bt[15],tat[15],wt[15];
    int ct[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        p[i]=i+1;
    }
 
    printf("Enter arrival time and burst time and priority of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&at[i],&bt[i],&pt[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-i-1);j++)
            {
                if(pt[j]>pt[j+1])
                {
                    temp=p[j+1];
                    p[j+1]=p[j];
                    p[j]=temp;
                    temp=at[j+1];
                    at[j+1]=at[j];
                    at[j]=temp;
                    temp=bt[j+1];
                    bt[j+1]=bt[j];
                    bt[j]=temp;
                    temp=pt[j+1];
                    pt[j+1]=pt[j];
                    pt[j]=temp;
                    
                }
            }
    }
    ct[0]=bt[0];
    for(int i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
    }

    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

     printf("Process ID     Burst Time     Completion Time     Waiting Time     TurnAround Time     Priority\n");
    float twt=0.0;
    float ttat= 0.0;
    for(int i=0; i<n; i++)
    {
        printf("%d\t\t", p[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", ct[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", tat[i]);
        printf("%d\t\t", pt[i]);
        printf("\n");

    }
}