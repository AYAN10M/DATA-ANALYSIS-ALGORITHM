#include <stdio.h>
#include <stdlib.h>

int factorial(int n, int dp[])
{
    if (n <= 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = n * factorial(n - 1, dp);
    return dp[n];
}

int main()
{
    int n;
    printf("Enter the number to get factorial of:\t");
    scanf("%d", &n);

    /*
        Must be wondering why n+1 and i <= n
        Let's us demonstrate with an example:

        for n = 5
        [   0,  1,  2,  3,  4,  5] the array size became 5+1 = 6 that's why n + 1
        [   1,  1,  2,  6,  24, 120]
    */
   
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    factorial(n, dp);

    printf("The factorial of %d is :\t%d", n, dp[n]);
    return 0;
}