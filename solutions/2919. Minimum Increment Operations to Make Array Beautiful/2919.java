class Solution {
  public long minIncrementOperations(int[] nums, int k) {
    long prev3 = 0; // min ops to increase nums[i - 3] and nums[:i - 3]
    long prev2 = 0; // min ops to increase nums[i - 2] and nums[:i - 2]
    long prev1 = 0; // min ops to increase nums[i - 1] and nums[:i - 1]

    for (final int num : nums) {
      final long dp = Math.min(prev1, Math.min(prev2, prev3)) + Math.max(0, k - num);
      prev3 = prev2;
      prev2 = prev1;
      prev1 = dp;
    }

    return Math.min(prev1, Math.min(prev2, prev3));
  }
}
