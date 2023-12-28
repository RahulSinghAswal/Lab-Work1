// FCFS Scheduling Program in C

#include <stdio.h>
int main()
{
    int pid[15], at[15];
    int bt[15], ct[15];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process id of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &pid[i]);
    }

    printf("Enter arrival time of all the processes:");
    for(int i =0; i< n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    int i, wt[n];
    wt[0] = 0;

    //for calculating completion time of each process
    ct[0] = at[0]+bt[0];
    for(i=1; i<n;i++) {
        ct[i] = ct[i-1] + bt[i];
    } 

    // for calculating waiting time of each process
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    printf("Process ID      Arrival Time     Burst Time      Waiting Time        TurnAround Time\n");
    float twt = 0.0;
    float tat = 0.0;
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%.d\t\t", wt[i]);

        // calculating and printing turnaround time of each process
        printf("%d\t\t", bt[i] + wt[i]);
        printf("\n");

        // for calculating total waiting time
        twt += wt[i];

        // for calculating total around time
        tat += bt[i] + wt[i];
    }

    float att, awt;

    // for calculating average waiting time
    awt = twt / n;

    // for calculating average turnaround time
    att = tat / n;

    printf("Avg. waiting time = %f\n", awt);
    printf("Avg. turnaround time = %f\n", att);
}
