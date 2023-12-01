class Solution {
  public long largestEvenSum(int[] nums, int k) {
    Arrays.sort(nums);

    long sum = 0;
    int minOdd = -1;
    int minEven = -1;
    int maxOdd = -1;
    int maxEven = -1;

    for (int i = nums.length - 1; i + k >= nums.length; --i) {
      sum += nums[i];
      if ((nums[i] & 1) == 1)
        minOdd = nums[i];
      else
        minEven = nums[i];
    }

    if (sum % 2 == 0)
      return sum;

    for (int i = 0; i + k < nums.length; ++i)
      if ((nums[i] & 1) == 1)
        maxOdd = nums[i];
      else
        maxEven = nums[i];

    long ans = -1;

    if (maxEven >= 0 && minOdd >= 0)
      ans = Math.max(ans, sum + maxEven - minOdd);
    if (maxOdd >= 0 && minEven >= 0)
      ans = Math.max(ans, sum + maxOdd - minEven);
    return ans;
  }
}
