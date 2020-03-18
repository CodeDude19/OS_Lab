#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int pid, bt, at, ct, wt, tt;
} process;

process proc[10];
int n, avgWT, avgTT;

int comp(const void *a, const void *b)
{
    const process *x = a;
    const process *y = b;
    return (x->at > y->at) - (x->at < y->at);
}

void display()
{
    printf("\n\nPID\tBT\tAT\tCT\tWT\tTT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t", proc[i].pid);
        printf("%d\t", proc[i].bt);
        printf("%d\t", proc[i].at);
        printf("%d\t", proc[i].ct);
        printf("%d\t", proc[i].wt);
        printf("%d", proc[i].tt);
        printf("\n");
    }
}

void schedule()
{
    int rt[n];
    for (int i = 0; i < n; i++)
    {
        rt[i] = proc[i].bt;
    }
    int compProcs = 0, currTime = 0, minBT = __INTMAX_MAX__, shortest = 0;
    bool check = false;
    while (compProcs != n)
    {
        for (int i = 0; i < n; i++)
        {
            if ((proc[i].at <= currTime) && (rt[i] < minBT) && (rt[i] > 0))
            {
                minBT = rt[i];
                shortest = i;
                check = true;
            }
        }

        if (!check)
        {
            currTime++;
            continue;
        }

        minBT = --rt[shortest];
        printf(" <--P%d--> %d", proc[shortest].pid, currTime + 1);

        if (rt[shortest] == 0)
        {
            minBT = __INTMAX_MAX__;
            compProcs++;
            check = false;
            proc[shortest].ct = currTime + 1;
            proc[shortest].tt = proc[shortest].ct - proc[shortest].at;
            proc[shortest].wt = proc[shortest].tt - proc[shortest].bt;
            avgWT += proc[shortest].wt;
            avgTT += proc[shortest].tt;
        }
        currTime++;
    }
}

int main()
{
    printf("Enter the number of processess: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        printf("P%d BT and AT: ", proc[i].pid);
        scanf("%d %d", &proc[i].bt, &proc[i].at);
    }
    qsort(proc, n, sizeof(*proc), comp);
    printf("\n\nGannt Chart:-\n0");
    schedule();
    display();
    printf("Average Waiting time : %0.2f\n", (float)avgWT / n);
    printf("Average Turn-Around time : %0.2f\n", (float)avgTT / n);
    return 0;
}