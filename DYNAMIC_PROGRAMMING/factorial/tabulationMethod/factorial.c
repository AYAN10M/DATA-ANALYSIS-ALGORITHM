#include <stdio.h>
#include <stdlib.h>

int factorial(int n, int dp[])
{
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] * i;
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter the term you wanted to get factorial of:\t");
    scanf("%d", &n);

    int dp[n + 1];

    factorial(n, dp);

    printf("Factorial of %d is :\t%d", n, dp[n]);
    return 0;
}