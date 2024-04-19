#include <stdio.h>
#include <stdlib.h>

typedef struct Job
{
    int id;
    int deadline;
    int profit;
} Job;

int jobSequenceWithDeadline(Job jobs[], int timeline[], int n, int maxDeadline)
{
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline <= maxDeadline)
        {
            int j = jobs[i].deadline - 1;
            while (j >= 0 && timeline[j] != -1)
            {
                j--;
            }
            if (j >= 0)
            {
                timeline[j] = jobs[i].id;
                profit += jobs[i].profit;
            }
        }
    }

    return profit;
}

int main()
{
    // n:   number of jobs
    int n;
    printf("Enter the number of jobs:\t");
    scanf("%d", &n);

    Job jobs[n];

    // for storing the max deadline among all the jobs avilable
    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for job number %d:\n", i + 1);
        printf("\tEnter the job id no:\t");
        scanf("%d", &jobs[i].id);
        printf("\tEnter the deadline for the given job:\t");
        scanf("%d", &jobs[i].deadline);
        printf("\tEnter the profit for the given job:\t");
        scanf("%d", &jobs[i].profit);

        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    // array to store which job occuping which time slot of the given array
    int timeline[maxDeadline];

    // initialize all the element in the timeline with -1
    for (int i = 0; i < maxDeadline; i++)
    {
        timeline[i] = -1;
    }

    // sorting the array in descending order of the job's cost
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (jobs[i].profit < jobs[j].profit)
            {
                int temp;

                temp = jobs[i].id;
                jobs[i].id = jobs[j].id;
                jobs[j].id = temp;

                temp = jobs[i].deadline;
                jobs[i].deadline = jobs[j].deadline;
                jobs[j].deadline = temp;

                temp = jobs[i].profit;
                jobs[i].profit = jobs[j].profit;
                jobs[j].profit = temp;
            }
        }
    }

    // after sorting
    printf("\nID\tDead\tProfit");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%d\t%d\t%d", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    }

    int maxProfit = jobSequenceWithDeadline(jobs, timeline, n, maxDeadline);
    printf("\nThe Maximum Profit could be gained will be :\t%d", maxProfit);

    return 0;
}