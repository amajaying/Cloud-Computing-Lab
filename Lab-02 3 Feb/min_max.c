#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid;
    int ct;
    int comp;
};

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int n;
    printf("Enter the no of processes ");
    scanf("%d", &n);

    int etcMatrix[2][n];
    struct process p[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the ETC for process %d on processor 1 ", i + 1);
        scanf("%d", &etcMatrix[0][i]);
        printf("Enter the ETC for process %d on processor 2 ", i + 1);
        scanf("%d", &etcMatrix[1][i]);
        p[i].comp = 0;
    }

    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = -1;
        arr2[i] = -1;
    }
    int j = 0, k = 0, l = 0;

    while (j < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].comp == 0)
            {
                if (etcMatrix[0][i] < etcMatrix[1][i])
                {
                    p[i].pid = 1;
                    p[i].ct = etcMatrix[0][i];
                }
                else
                {
                    p[i].pid = 2;
                    p[i].ct = etcMatrix[1][i];
                }
            }
        }
        int flagCompleted = 1;
        int maxCT = -999999;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].comp == 0)
            {
                flagCompleted = 0;
                maxCT = max(maxCT, p[i].ct);
                if (maxCT == p[i].ct)
                {
                    index = i;
                }
            }
        }
        if (flagCompleted == 1)
        {
            break;
        }
        else
        {
            p[index].comp = 1;
            if (p[index].pid == 1)
            {
                arr1[k++] = index + 1;
                for (int i = 0; i < n; i++)
                {
                    if (p[i].comp == 0)
                    {
                        etcMatrix[0][i] += maxCT;
                    }
                }
            }
            else
            {
                arr2[l++] = index + 1;
                for (int i = 0; i < n; i++)
                {
                    if (p[i].comp == 0)
                    {
                        etcMatrix[1][i] += maxCT;
                    }
                }
            }
        }
        j++;
    }

    printf("The order of processes on processor 1 is ");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    printf("The order of processes on processor 2 is ");
    for (int i = 0; i < l; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    return 0;
}