#include <stdio.h>

#define min(a, b) (a < b) ? a : b

int main()
{
    int p = 2, t;
    printf("Enter the no of tasks: ");
    scanf("%d", &t);

    int etm[p][t];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < t; j++)
        {
            scanf("%d", &etm[i][j]);
        }
    }
    int total_time[2] = {0, 0};

    int min_t[t];
    int ind_t[t];
    int flag[t];

    // saare flag ko 0 kara
    for (int i = 0; i < t; i++)
    {
        flag[i] = 0;
    }

    int done_task = 0;
    while (done_task < t)
    {
        // minimum task with process index nikala
        for (int i = 0; i < t; i++)
        {
            if(flag[i]==0){
                min_t[i] = min(etm[0][i], etm[1][i]);
                if (etm[0][i] < etm[1][i])
                    ind_t[i] = 0;
                else
                    ind_t[i] = 1;

                printf("%d - %d", ind_t[i], min_t[i]);
                printf("\n");
            }
            else
                continue;
        }
        done_task++;

        // flag wala
        int minm = 99999;
        for(int i=0; i<t; i++){
            minm = min(min_t[i], minm);
        }

        for(int i=0; i<t; i++){
            if(minm == min_t[i]){
                flag[i] = 1;
            }
        }


        // ab minimum task ko assign karunga
        int min_task[2] = {10000, 10000};

        for (int i = 0; i < t; i++)
        {
            if(min_task[ind_t[i]] < min_t[i]){
                min_task[ind_t[i]] = min_task[ind_t[i]];
            
            }            
            else{
                min_task[ind_t[i]] = min_t[i];
            }
        }

        printf("Min Task of P1: %d\n", min_task[0]);
        printf("Min Task of P2: %d\n", min_task[1]);
        printf("\n");

        min_task[0] = 10000;
        min_task[1] = 10000;
        printf("\n Flag: ");
        for(int i=0; i<t; i++){
            printf("%d, ", flag[i]);
        }
    }
}