#include <stdio.h>
#include <limits.h>

typedef struct
{
    int pid;
    int st;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int visited;
} sjf;

int main()
{
    int n;
    printf("Enter the no of process: ");
    scanf("%d", &n);
    sjf p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        printf("\nEnter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        p[i].pid = i + 1;
        p[i].visited = 0;
    }
    float avg_wt=0,avg_tt=0;
    int completed = 0; 
    int curr_time = 0; 
    while (completed != n)
    {
        int min_index = -1;
        int min_time = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= curr_time && p[i].bt < min_time && p[i].visited == 0)
            {
                min_index = i;
                min_time = p[i].bt;
            }
            else if (p[i].bt == min_time) 
            {
                if (p[i].at < p[min_index].at)
                {
                    min_index = i;
                }
            }
        }
        if (min_index == -1) 
            curr_time++;
        else
        {           
            p[min_index].st = curr_time;
            p[min_index].ct = p[min_index].st + p[min_index].bt;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;
            p[min_index].rt = p[min_index].wt;
            avg_wt+=p[min_index].wt;
            avg_tt+=p[min_index].tat;

            completed++;
            p[min_index].visited = 1;
            curr_time = p[min_index].ct;
    
        }
    }
    printf("The average waiting time is: %.2f\n", avg_wt/n);
    printf("The average turnaround time is: %.2f\n",avg_tt/n);
    
}