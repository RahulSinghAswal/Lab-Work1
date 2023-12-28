#include <stdio.h>
#include <stdlib.h>
typedef struct process
{
    int num;
    int arrive;
    int brust;
    int pt;
    int f;
    int cpu;
    int wait;
} process;

typedef struct queue
{
    process p[10];
    int front;
    int rear;
} queue;
void insert(queue *q, process t)
{
    q->p[q->rear] = t;
    q->rear++;
}
void pstack(queue *que)
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("\n queue %d is \n", i + 1);
        printf("Process\tArrival Time\tBrust Time\t Type\t I/O\t CPU \tWaiting Time\n");
        for (j = 0; j < que[i].rear; j++)
        {
            printf(" %d \t\t %d \t\t %d \t %d \t %d \t %d \t %d\ n", que[i].p[j].num, que[i].p[j].arrive, que[i].p[j].brust, que[i].p[j].pt, que[i].p[j].f, que[i].p[j].cpu, que[i].p[j].wait);
        }
    }
}
void fcfs_sort(queue *que)
{
    process *temp;
    int i, j, k, n;
    for (k = 0; k < 3; k++)
    {
        n = que[k].rear;
        for (i = 1; i < n; i++)
        {
            for (j = 0; j < n - i; j++)
            {
                if (que[k].p[j].arrive > que[k].p[j + 1].arrive)
                {
                    temp = &que[k].p[j];
                    que[k].p[j] = que[k].p[j + 1];
                    que[k].p[j + 1] = *temp;
                }
            }
        }
    }
}
void pque(queue *que)
{
    int c = 0, cp = 0;
    int w = 0;
    int j = 0, k = 0, l = 0, t = 0, i;
    process *temp;
    int max = 0;
    for (i = 0; i < 3; i++)
    {
        max = max + que[i].rear;
    }
    for (i = 0; i < max; i++)
    {
        if (que[0].p[j].arrive <= cp && j < que[0].rear)
        {
            que[0].p[j].cpu = c;
            que[0].p[j].wait = c - que[0].p[j].arrive;
            if (que[0].p[j].wait < 1)
                que[0].p[j].wait = 0;
            c = c + que[0].p[j].brust;
            j++;
            cp = c;
            continue;
        }
        else if (que[1].p[k].arrive < cp && k < que[1].rear)
        {
            que[1].p[k].cpu = c;
            que[1].p[k].wait = c - que[1].p[k].arrive;
            if (que[1].p[k].wait < 1)
                que[1].p[k].wait = 0;
            c = c + que[1].p[k].brust;
            k++;
            cp = c;
            continue;
        }
        else if (que[2].p[l].arrive < cp && l < que[2].rear)
        {
            que[2].p[l].cpu = c;
            que[2].p[l].wait = c - que[2].p[l].arrive;
            if (que[2].p[l].wait < 1)
                que[2].p[l].wait = 0;
            c = c + que[2].p[l].brust;
            l++;
        }
        else
            c = 0;
    }
}
int main()
{
    queue que[3];
    int j;
    for (j = 0; j < 3; j++)
    {
        que[j].front = -1;
        que[j].rear = 0;
    }
    process temp;
    int n;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        temp.num = i + 1;
        temp.cpu = 0;
        temp.wait = 0;
        printf("\nEnter the arrival time of process%d =", i + 1);
        scanf("%d", &temp.arrive);
        printf("\nEnter the brust time of process %d =", i + 1);
        scanf("%d", &temp.brust);
        printf("\nEnter the type of(1-back,2-foreground,3-other) process %d =", i + 1);
        scanf("%d", &temp.pt);
        printf("\nEnter the feedback of process(0-for normal,1-I/O) %d =", i + 1);
        scanf("%d", &temp.f);
        if (temp.pt >= 2 && temp.f == 1)
            insert(&que[temp.pt - 2], temp);
        else if (temp.f == 0)
            insert(&que[temp.pt - 1], temp);
        else
            insert(&que[temp.pt - 1], temp);
    }
    pstack(que);
    fcfs_sort(que);
    printf("\n\nAfter sorting of process list is \n\n");
    pstack(que);
    pque(que);
    printf("\n\nAfter processing CPU and wait is \n\n");
    pstack(que);
    return 0;
}