#include <stdio.h>

int main()
{
    int burstTime[] = {10, 5, 8};
    int remainingTime[] = {10, 5, 8};

    int n = 3;
    int quantum = 2;
    int completed = 0;

    printf("Round Robin Scheduling Simulation\n\n");

    while(completed < n)
    {
        for(int i = 0; i < n; i++)
        {
            if(remainingTime[i] > 0)
            {
                if(remainingTime[i] > quantum)
                {
                    printf("Process P%d executes for %d units\n", i + 1, quantum);
                    remainingTime[i] -= quantum;
                }
                else
                {
                    printf("Process P%d executes for %d units and finishes\n",
                           i + 1,
                           remainingTime[i]);

                    remainingTime[i] = 0;
                    completed++;
                }
            }
        }
    }

    printf("\nAll processes completed.\n");

    return 0;
}
