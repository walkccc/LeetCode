class Solution {
  public int waysToDistribute(int n, int k) {
    final int kMod = 1_000_000_007;
    // dp[i][j] := the number of ways to distribute i candies to j bags
    // dp[i][j] = 0, if i < j
    //          = 1, if i == j
    //          = dp[i - 1][j - 1] (the new candy occupies a bag)
    //          + dp[i - 1][j] * j (the new candy is in any of the j bags)
    long[][] dp = new long[n + 1][k + 1];

    for (int i = 0; i <= k; ++i)
      dp[i][i] = 1;

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= k; ++j)
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % kMod;

    return (int) dp[n][k];
  }
}
