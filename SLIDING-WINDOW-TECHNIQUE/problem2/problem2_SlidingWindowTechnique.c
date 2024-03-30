long long countSubarrays(int *nums, int numsSize, int k) {
  int i = 0;
  int j = 0;

  // for finding the max element in the array
  int max = 0;
  for (int m = 0; m < numsSize; m++) {
    if (nums[m] > max) {
      max = nums[m];
    }
  }

  long long ans = 0;

  // for frequency counting
  int freq[1000001] = {0};
  while (j < numsSize) {
    freq[nums[j]]++;
    while (freq[max] >= k && freq[max] > 0) {
      freq[nums[i]]--;
      ans += numsSize - j;
      i++;
    }
    j++;
  }

  return ans;
}
