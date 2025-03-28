class Solution {
  // Same as 2908. Minimum Sum of Mountain Triplets I
  public int minimumSum(int[] nums) {
    final int n = nums.length;
    int ans = Integer.MAX_VALUE;
    int[] minPrefix = new int[n];
    int[] minSuffix = new int[n];

    minPrefix[0] = nums[0];
    minSuffix[n - 1] = nums[n - 1];

    for (int i = 1; i < n; ++i)
      minPrefix[i] = Math.min(minPrefix[i - 1], nums[i]);

    for (int i = n - 2; i >= 0; --i)
      minSuffix[i] = Math.min(minSuffix[i + 1], nums[i]);

    for (int i = 0; i < n; ++i)
      if (nums[i] > minPrefix[i] && nums[i] > minSuffix[i])
        ans = Math.min(ans, nums[i] + minPrefix[i] + minSuffix[i]);

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
