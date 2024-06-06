class Solution {
  public long minOperationsToMakeMedianK(int[] nums, int k) {
    final int n = nums.length;
    long ans = 0;

    Arrays.sort(nums);

    for (int i = 0; i <= n / 2; ++i)
      ans += Math.max(0, nums[i] - k);

    for (int i = n / 2; i < n; ++i)
      ans += Math.max(0, k - nums[i]);

    return ans;
  }
}
