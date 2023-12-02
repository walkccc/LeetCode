class Solution {
  public int waysToDistribute(int n, int k) {
    final int kMod = 1_000_000_007;
    long[][] dp = new long[k + 1][n + 1];

    for (int i = 0; i <= k; ++i)
      dp[i][i] = 1;

    for (int i = 1; i <= k; ++i)
      for (int j = i + 1; j <= n; ++j)
        dp[i][j] = (dp[i - 1][j - 1] + i * dp[i][j - 1]) % kMod;

    return (int) dp[k][n];
  }
}
