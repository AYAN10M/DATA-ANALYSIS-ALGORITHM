#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications
int matrixChainMultiplication(int arr[], int i, int j) {

  // Base case: single matrix
  if (i == j) {
    return 0;
  }

  // Use a larger integer type to avoid overflow
  int min = INT_MAX;
  int k, count;

  // Iterate through all possible partition points
  for (k = i; k < j; k++) {
    count = matrixChainMultiplication(arr, i, k) +
            matrixChainMultiplication(arr, k + 1, j) +
            arr[i - 1] * arr[k] * arr[j];

    if (count < min) {
      min = count;
    }
  }

  // Return minimum count
  return min;
}

int main() {
  int n;

  printf("Enter the number of matrices:\t");
  scanf("%d", &n);

  int arr[n];
  printf("Enter dimensions of the matrices:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int min = matrixChainMultiplication(arr, 1, n - 1);
  printf("The minimum number of matrix multiplication needed is %d\n", min);

  return 0;
}
