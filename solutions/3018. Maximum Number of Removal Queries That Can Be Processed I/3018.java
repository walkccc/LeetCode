class Solution {
  public int maximumProcessableQueries(int[] nums, int[] queries) {
    final int n = nums.length;
    int ans = 0;
    // dp[i][j] := the maximum number of queries processed if nums[i..j] are not
    // removed after processing dp[i][j] queries
    int[][] dp = new int[n][n];

    for (int d = n - 1; d >= 0; --d) {
      for (int i = 0; i < n; ++i) {
        final int j = i + d;
        if (j >= n)
          continue;
        if (i > 0)
          // Remove nums[i - 1] from nums[i - 1..j] if possible.
          dp[i][j] =
              Math.max(dp[i][j], dp[i - 1][j] + (nums[i - 1] >= queries[dp[i - 1][j]] ? 1 : 0));
        if (j + 1 < n)
          // Remove nums[j + 1] from nums[i..j + 1] if possible.
          dp[i][j] =
              Math.max(dp[i][j], dp[i][j + 1] + (nums[j + 1] >= queries[dp[i][j + 1]] ? 1 : 0));
        if (dp[i][j] == queries.length)
          return queries.length;
      }
    }

    for (int i = 0; i < n; ++i)
      ans = Math.max(ans, dp[i][i] + (nums[i] >= queries[dp[i][i]] ? 1 : 0));

    return ans;
  }
}
