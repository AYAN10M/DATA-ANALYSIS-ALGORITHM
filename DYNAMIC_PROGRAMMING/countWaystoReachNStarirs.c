/*
    How to understand a particular question is of 1D dynamic programming
    -> Count the total number of ways
    -> Try all possible ways
*/

/*
    Problem Statement:

    You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair.

    Each time, you can climb either one step or two steps.

    You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

    We can climb one step at a time i.e. {(0, 1) ,(1, 2),(2,3)} or we can climb the first two-step and then one step i.e. {(0,2),(1, 3)} or we can climb first one step and then two step i.e. {(0,1), (1,3)}.
*/

#include <stdio.h>
#include <stdlib.h>

// memoziation approch

int countSteps(int n, int dp[])
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = countSteps(n - 1, dp) + countSteps(n - 2, dp);

    return dp[n];
}

int main()
{
    // the stair need to climb
    int n;
    printf("Enter the number of steps:\t");
    scanf("%d", &n);

    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = -1;
    }

    printf("The total no of possible way we can climb the given steps are: %d\n", countSteps(n, dp));
    return 0;
}