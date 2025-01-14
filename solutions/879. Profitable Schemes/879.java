class Solution {
  public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
    final int kMod = 1_000_000_007;
    // dp[k][i][j] := the number of schemes, where the first k crimes are
    // committed by <= i members, generating >= j profits
    int[][][] dp = new int[group.length + 1][n + 1][minProfit + 1];

    // No crimes, no profits, and any number of members.
    for (int i = 0; i <= n; ++i)
      dp[0][i][0] = 1;

    for (int k = 1; k <= group.length; ++k) {
      final int g = group[k - 1];
      final int p = profit[k - 1];
      for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= minProfit; ++j)
          if (i < g) {
            dp[k][i][j] = dp[k - 1][i][j];
          } else {
            dp[k][i][j] = dp[k - 1][i][j] + dp[k - 1][i - g][Math.max(0, j - p)];
            dp[k][i][j] %= kMod;
          }
    }

    return dp[group.length][n][minProfit];
  }
}
