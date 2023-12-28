//SJF (Shortest Job First) Algorithm Implementation

#include<stdio.h>

int main(){
    int bt[20], p[20], wt[20], tat[20], i, j,n, total=0, pos, temp;
    float avg_wt, avg_tat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:");
    for (i = 0; i< n; i++) {
        printf("P%d : ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    //sorting of burst times
    for(i = 0; i<n;i++) {
        pos =i; 
        for(j=i+1; j <n;j++) {
            if(bt[j]<bt[pos])
            pos = j;
        }

        tem
    }
}