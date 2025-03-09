class Solution {
  public int maximumProfit(int[] present, int[] future, int budget) {
    final int n = present.length;
    // dp[i][j] := the maximum profit of buying present[0..i) with j budget
    int[][] dp = new int[n + 1][budget + 1];

    for (int i = 1; i <= n; ++i) {
      final int profit = future[i - 1] - present[i - 1];
      for (int j = 0; j <= budget; ++j)
        if (j < present[i - 1])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = Math.max(dp[i - 1][j], profit + dp[i - 1][j - present[i - 1]]);
    }

    return dp[n][budget];
  }
}
