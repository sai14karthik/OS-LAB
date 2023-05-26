#include<stdio.h>
#define MAX_PROCESS 10

int main()
{
    int AT[MAX_PROCESS], BT[MAX_PROCESS], PT[MAX_PROCESS];
    int WT[MAX_PROCESS], TAT[MAX_PROCESS];
    int n, temp[MAX_PROCESS], t, count = 0, short_p;
    float total_WT = 0, total_TAT = 0, Avg_WT, Avg_TAT;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the arrival time, burst time, and priority of the processes:\n");
    printf("AT BT PT\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &AT[i], &BT[i], &PT[i]);
        
        // copying the burst time in a temp array for further use
        temp[i] = BT[i];
    }
    
    // initialize the priority of the last process to a maximum value
    PT[n - 1] = 10000;
    
    for (t = 0; count != n; t++)
    {
        short_p = n - 1;
        
        for (int i = 0; i < n; i++)
        {
            if (PT[short_p] > PT[i] && AT[i] <= t && BT[i] > 0)
            {
                short_p = i;
            }
        }
        
        BT[short_p] = BT[short_p] - 1;
        
        // if any process is completed
        if (BT[short_p] == 0)
        {
            // one process is completed, so count increases by 1
            count++;
            WT[short_p] = t + 1 - AT[short_p] - temp[short_p];
            TAT[short_p] = t + 1 - AT[short_p];
            
            // total calculation
            total_WT = total_WT + WT[short_p];
            total_TAT = total_TAT + TAT[short_p];
        }
    }
    
    Avg_WT = total_WT / n;
    Avg_TAT = total_TAT / n;
    
    // printing the results
    printf("ID WT TAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\t%d\n", i + 1, WT[i], TAT[i]);
    }
    
    printf("Avg waiting time of the processes is %f\n", Avg_WT);
    printf("Avg turnaround time of the processes is %f\n", Avg_TAT);
    
    return 0;
}
