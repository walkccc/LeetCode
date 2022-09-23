class Solution {
  public int numOfArrays(int n, int m, int k) {
    final int kMod = 1_000_000_007;
    // dp[i][j][k] := # of ways to build an array of length i, where j is the
    // max num and k is the `search_cost`
    int[][][] dp = new int[n + 1][m + 1][k + 1];
    // prefix[i][j][k] := sum(dp[i][x][k]), where 1 <= x <= j
    int[][][] prefix = new int[n + 1][m + 1][k + 1];

    for (int j = 1; j <= m; ++j) {
      dp[1][j][1] = 1;
      prefix[1][j][1] = j;
    }

    for (int i = 2; i <= n; ++i)                // for each length
      for (int j = 1; j <= m; ++j)              // for each max value
        for (int cost = 1; cost <= k; ++cost) { // for each cost
          // 1. appending any of [1, j] in i-th position
          //    doesn't change the max and cost
          // 2. appending j in i-th position
          //    make j the new max and cost 1
          dp[i][j][cost] =
              (int) (((long) j * dp[i - 1][j][cost] + prefix[i - 1][j - 1][cost - 1]) % kMod);
          prefix[i][j][cost] = (dp[i][j][cost] + prefix[i][j - 1][cost]) % kMod;
        }

    int ans = 0;
    for (int j = 1; j <= m; ++j) {
      ans += dp[n][j][k];
      ans %= kMod;
    }
    return ans;
  }
}
