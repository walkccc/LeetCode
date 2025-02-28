class Solution {
  public long minIncrementOperations(int[] nums, int k) {
    // the minimum operations to increase nums[i - 3] and nums[0..i - 3)
    long prev3 = 0;
    // the minimum operations to increase nums[i - 2] and nums[0..i - 2)
    long prev2 = 0;
    // the minimum operations to increase nums[i - 1] and nums[0..i - 1)
    long prev1 = 0;

    for (final int num : nums) {
      final long dp = Math.min(prev1, Math.min(prev2, prev3)) + Math.max(0, k - num);
      prev3 = prev2;
      prev2 = prev1;
      prev1 = dp;
    }

    return Math.min(prev1, Math.min(prev2, prev3));
  }
}
