#include <stdio.h>
#include <stdlib.h>

int knapsack(int size, int capacity)
{
	float weight[size], profit[size], ratio[size];
	int i, j;
	float result = 0;
	
	for(i = 0; i < size; i++)
	{
		printf("Enter the weight for item %d:\t", i);
		scanf("%f", &weight[i]);
		printf("Enter the profit for item %d:\t", i);
		scanf("%f", &profit[i]);
		
		ratio[i] = profit[i]/weight[i];
	}
	
	for(i = 0; i < size - 1; i++)
	{
		for(j = i+1; j < size; j++)
		{
			if(ratio[i] < ratio[j])
			{
				float temp;
				temp = ratio[j];
				ratio[j] = ratio[i];
				ratio[i] = temp;
				
				temp = profit[j];
				profit[j] = profit[i];
				profit[i] = temp;
				
				temp = weight[j];
				weight[j] = weight[i];
				weight[i] = temp;
			}
		}
	}
	
	i = 0;
	while(capacity != 0)
	{
		if(capacity >= weight[i])
		{
			capacity -= weight[i];
			result += profit[i];
			i++;	
		}
		
		if(i == size-1)
		{
			break;
		}
		
		if(capacity < weight[i])
		{
			result += (capacity/weight[i]) * profit[i];
			capacity = 0;
		}
	}
	return result;
}

int main()
{
	// n is number of items
	int  n;
	printf("Enter the number of items:\t");
	scanf("%d", &n);
	
	float capacity;
	printf("Enter the capacity of knap sack:\t");
	scanf("%f", &capacity);
	
	float amount = knapsack(n, capacity);
	printf("The profit amount is :\t %f", amount);
	return 0;
}