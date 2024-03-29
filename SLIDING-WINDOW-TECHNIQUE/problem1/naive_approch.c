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

    int maxSum = -99999, cSum = 0;

    /*
        for example suppose our k is 3
        the for array [2, 9, 31, -4, 21, 7] our i can only go upto
                                  i

        that why here we use n - k
    */
    for (int i = 0; i < n - k + 1; i++)
    {
        cSum = 0;
        for (int j = i; j < i + k; j++)
        {
            cSum += arr[j];
        }
        if (cSum > maxSum)
        {
            maxSum = cSum;
        }
    }

    printf("%d", maxSum);
}