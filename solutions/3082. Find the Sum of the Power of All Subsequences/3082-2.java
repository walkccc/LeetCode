class Solution {
  public int sumOfPower(int[] nums, int k) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    // dp[i][j] := the number of subsequences in nums[0..i) that sums to k
    int[][] dp = new int[n + 1][k + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
      final int num = nums[i - 1];
      for (int j = 0; j <= k; ++j)
        if (j < num)
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          dp[i][j] = (int) ((dp[i - 1][j] * 2L) % kMod);
        else
          // 1. Exclude nums[i] in the subsequence.
          // 2. Include nums[i] in the subsequence and skip it.
          // 3. Include nums[i] in the subsequence and pick it.
          dp[i][j] = (int) ((dp[i - 1][j] * 2L + dp[i - 1][j - num]) % kMod);
    }

    return dp[n][k];
  }
}
