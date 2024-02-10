#include <stdio.h>

typedef struct
{
    int pid;
    int ct;
    int bt;
    int at;
    int tt;
    int wt;
} fcfs;

void sort(fcfs *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                fcfs temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void calc(fcfs *p, int n)
{
    p[0].ct = p[0].at + p[0].bt;
    p[0].tt = p[0].ct - p[0].at;
    p[0].wt = p[0].tt - p[0].bt;
    float avg_tt = p[0].tt;
    float avg_wt = p[0].wt;
    for (int i = 1; i < n; i++)
    {
        int temp = 0;
        if (p[i].at > p[i - 1].ct)
        {
            temp = p[i].at - p[i - 1].ct;
        }
        p[i].ct = p[i - 1].ct + p[i].bt + temp;
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;

        avg_tt += p[i].tt;
        avg_wt += p[i].wt;
    }

    printf("The average waiting time is: %.2f\n", avg_wt / n);
    printf("The average turnaround time is: %.2f\n", avg_tt / n);
}

int main()
{
    int n;
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    fcfs p[n];
    printf("Enter the Arrival Time & Burst Time for each processes: \n");
    for (int i = 0; i < n; i++)
    {
        printf("For process %d:\n", i + 1);
        p[i].pid = i + 1;
        printf("\nEnter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("\nEnter Burst Time: ");
        scanf("%d", &p[i].bt);
    }
    sort(p, n);
    calc(p, n);
}