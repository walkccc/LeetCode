class Solution {
  public int numOfArrays(int n, int m, int k) {
    final int MOD = 1_000_000_007;
    // dp[i][j][k] := the number of ways to build an array of length i, where j
    // is the maximum number and k is `search_cost`
    int[][][] dp = new int[n + 1][m + 1][k + 1];

    for (int j = 1; j <= m; ++j)
      dp[1][j][1] = 1;

    for (int i = 2; i <= n; ++i)                // for each length
      for (int j = 1; j <= m; ++j)              // for each max value
        for (int cost = 1; cost <= k; ++cost) { // for each cost
          // 1. Appending any of [1, j] in the i-th position doesn't change the
          //    maximum and cost.
          dp[i][j][cost] = (int) ((long) j * dp[i - 1][j][cost] % MOD);
          // 2. Appending j in the i-th position makes j the new max and cost 1.
          for (int prevMax = 1; prevMax < j; ++prevMax) {
            dp[i][j][cost] += dp[i - 1][prevMax][cost - 1];
            dp[i][j][cost] %= MOD;
          }
        }

    int ans = 0;
    for (int j = 1; j <= m; ++j) {
      ans += dp[n][j][k];
      ans %= MOD;
    }
    return ans;
  }
}
