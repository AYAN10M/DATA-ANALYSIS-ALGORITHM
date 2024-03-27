#include <stdio.h>
#include <stdlib.h>

int knapsack(int n, int arr[], int value[], int weight[], int amount)
{
    int knapsack[n];
    for (int i = 0; i < n; i++)
    {
        knapsack[i] = value[i] / weight[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (knapsack[i] < knapsack[j])
            {
                int temp = knapsack[i];
                knapsack[i] = knapsack[j];
                knapsack[j] = temp;

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

                temp = value[i];
                value[i] = value[j];
                value[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    int profit = 0;
    while (amount != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (weight[i] <= amount)
            {
                profit += value[i];
                amount -= weight[i];
            }
        }
    }

    return profit; // Return the calculated profit
}

int main()
{
    // total number of items
    int n;
    printf("Enter the number of items:\t");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int value[n];
    int weight[n];

    printf("Item\tValue\tWeight\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
        scanf("%d\t%d", &value[i], &weight[i]);
    }

    int amount;
    printf("Enter the capacity of knapsack:\t");
    scanf("%d", &amount);

    int profit = knapsack(n, arr, value, weight, amount);
    printf("Maximum profit: %d\n", profit);
    return 0;
}
