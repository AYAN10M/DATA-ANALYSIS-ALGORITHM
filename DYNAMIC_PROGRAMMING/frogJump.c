/*
    Problem Statement

    There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair. If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

    For Example
    If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.
*/

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }

    if (b > a)
    {
        return a;
    }
}

int minStep(int n, int height[], int dp[])
{
    int dp[0] = 0;
    int dp[1] = 0;

    
}

int main()
{
    int n;
    printf("Enter the number of steps:\t");
    scanf("%d", &n);

    int height[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height[i]);
    }

    int dp[n + 1];

    printf("Minimum energy the frog will need to reach step n: %d", minStep(n, height, dp));
    return 0;
}