class Solution {
  public int sumOfPower(int[] nums, int k) {
    final int kMod = 1_000_000_007;
    // dp[i] := the number of subsequences in nums so far that sums to k
    int[] dp = new int[k + 1];
    dp[0] = 1;

    for (final int num : nums)
      for (int i = k; i >= 0; --i)
        if (i < num)
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          dp[i] = (int) ((dp[i] * 2L) % kMod);
        else
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          // 3. Include nums[i] in the subsequence and pick it.
          dp[i] = (int) ((dp[i] * 2L + dp[i - num]) % kMod);

    return dp[k];
  }
}
