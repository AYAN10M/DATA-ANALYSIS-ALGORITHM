#include <stdio.h>
#include <stdlib.h>

int subarraysWithKDistinct(int *nums, int numsSize, int k)
{
    int i = 0, j = i + 1, count = 0, result = 0, flag = 1;
    for (i = 0; i < numsSize; i++)
    {
        while (j <= numsSize)
        {
            if (nums[i] != nums[j])
            {
                j++;
                count++;
                if (count >= k)
                {
                    result++;
                }
            }
            else
            {
                if (i <= k)
                {
                    j++;
                }
            }
        }
    }
    return result;
}