#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n, int dp[])
{
    // base case
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        // Check if the value is already calculated
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Calculate and store the value for future use
        dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
        return dp[n];
    }
}

int main()
{
    int n;
    printf("Enter the number of terms:\t");
    scanf("%d", &n);

    int dp[n + 1];

    // Initialize the DP array with -1 to indicate uncalculated values
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", fibonacci(i, dp));
    }

    return 0;
}
