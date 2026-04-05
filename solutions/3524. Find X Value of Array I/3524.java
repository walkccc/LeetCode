class Solution {
  public long[] resultArray(int[] nums, int k) {
    long[] ans = new long[k];
    // dp[r] := the number of subarrays ending at current position with
    // product % k == r
    long[] dp = new long[k];

    for (final int num : nums) {
      long[] newDp = new long[k];
      final int numMod = num % k;
      // Start new subarray with only `num`.
      newDp[numMod] = 1;
      // Extend all previous subarrays.
      for (int i = 0; i < k; ++i) {
        final int newMod = (int) (1L * i * numMod % k);
        newDp[newMod] += dp[i];
      }
      // Accumulate counts into ans.
      for (int i = 0; i < k; ++i)
        ans[i] += newDp[i];
      dp = newDp;
    }

    return ans;
  }
}
