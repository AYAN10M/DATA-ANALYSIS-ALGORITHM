#include <stdio.h>
#include <stdlib.h>

int fabonacci(int n, int dp[])
{
    if (n <= 1)
    {
        return n;
    }

    dp[0] = 0, dp[1] = 1;

    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter the number of terms:\t");
    scanf("%d", &n);
    int dp[n];

    fabonacci(n, dp);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", dp[i]);
    }
    return 0;
}