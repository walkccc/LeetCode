class Solution {
  public int splitArray(int[] nums, int m) {
    final int n = nums.length;
    // dp[i][k] := min of largest sum to split first i nums into k groups
    int[][] dp = new int[n + 1][m + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    int[] prefix = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
      prefix[i] = prefix[i - 1] + nums[i - 1];
      dp[i][1] = prefix[i];
    }

    for (int k = 2; k <= m; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j)
          dp[i][k] = Math.min(dp[i][k], Math.max(dp[j][k - 1], prefix[i] - prefix[j]));

    return dp[n][m];
  }
}
