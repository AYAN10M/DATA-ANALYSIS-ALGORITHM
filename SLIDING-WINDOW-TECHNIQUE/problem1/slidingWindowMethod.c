#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the array:\t");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the element of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // k is the lenght of the sub array
    int k;
    printf("Enter the size of the sub array:\t");
    scanf("%d", &k);

    // wSum for window sum
    // cSum for current sum

    int maxSum = -99999, wSum = 0;

    for (int i = 0; i < k; i++)
    {
        wSum += arr[i];
    }
    

    for (int i = k; i < n; i++)
    {
        wSum = wSum - arr[i - k] + arr[i];

        if (wSum > maxSum)
        {
            maxSum = wSum;
        }
    }
    printf("%d", maxSum);
    return 0;
}