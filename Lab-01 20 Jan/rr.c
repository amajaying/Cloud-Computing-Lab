#include <stdio.h>
#define max(a, b) (a > b) ? a : b

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
    int remain_bt;
} rr;

typedef struct
{
    int f, r;
    int data[100];
} queue;

void init(queue *q)
{
    q->f = q->r = -1;
}

void push(queue *q, int val)
{
    if (q->r == -1)
    {
        q->f = q->r = 0;
        q->data[q->r] = val;
    }
    else
    {
        q->data[++q->r] = val;
    }
}
void pop(queue *q)
{
    if (q->f == q->r)
    {
        q->f = q->r = -1;
    }
    else
        q->f++;
}
int empty(queue q)
{
    if (q.f == -1)
        return 1;
    else
        return 0;
}
int peek(queue q)
{
    return (q.data[q.f]);
}
void sort(rr *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                rr temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n, qt, count = 0;
    printf("Enter the no of process: ");
    scanf("%d", &n);
    printf("Enter the quantum time: ");
    scanf("%d", &qt);
    queue q;
    init(&q);
    rr p[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        printf("\nEnter Arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst time: ");
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
        p[i].visited = 0;
        p[i].remain_bt = p[i].bt;
    }

    sort(p, n);
    push(&q, 0);
    count++;
    p[0].visited = 1;
    float avg_wt = 0, avg_tt = 0;
    int completed = 0;
    int curr_time = 0;
    while (completed != n)
    {
        int x = peek(q);
        pop(&q);
        if (p[x].remain_bt == p[x].bt)
        {
            p[x].st = max(curr_time, p[x].at);
            curr_time = p[x].st;
        }
        if ((p[x].remain_bt - qt) > 0)
        {
            p[x].remain_bt -= qt;
            curr_time += qt;
        }
        else
        {
            curr_time += p[x].remain_bt;
            p[x].remain_bt = 0;
            p[x].ct = curr_time;
            p[x].tat = p[x].ct - p[x].at;
            p[x].wt = p[x].tat - p[x].bt;
            p[x].rt = p[x].st - p[x].at;
            avg_wt += p[x].wt;
            avg_tt += p[x].tat;
            completed++;
        }

        for (int i = 1; i < n; i++)
        {
            if (count == n)
                break;
            if (p[i].visited == 0 && p[i].remain_bt > 0 && p[i].at <= curr_time)
            {
                push(&q, i);
                count++;
                p[i].visited = 1;
            }
        }

        if (p[x].remain_bt > 0)
            push(&q, x);

        if (empty(q))
        {
            for (int i = 1; i < n; i++)
            {
                if (p[i].remain_bt > 0)
                {
                    push(&q, i);
                    p[i].visited = 1;
                    break;
                }
            }
        }
    }
    printf("The average waiting time is: %.2f\n", avg_wt / n);
    printf("The average turnaround time is: %.2f\n", avg_tt / n);
}