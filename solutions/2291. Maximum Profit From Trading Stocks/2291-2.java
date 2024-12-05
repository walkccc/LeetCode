class Solution {
  public int maximumProfit(int[] present, int[] future, int budget) {
    final int n = present.length;
    // dp[i] := the maximum profit of buying present so far with i budget
    int[] dp = new int[budget + 1];

    for (int i = 0; i < n; ++i)
      for (int j = budget; j >= present[i]; --j)
        dp[j] = Math.max(dp[j], future[i] - present[i] + dp[j - present[i]]);

    return dp[budget];
  }
}
