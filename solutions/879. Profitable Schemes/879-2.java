class Solution {
  public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
    final int kMod = 1_000_000_007;
    // dp[i][j] := the number of schemes, where <= i members, generating
    // >= j profits
    int[][] dp = new int[n + 1][minProfit + 1];

    for (int i = 0; i <= n; ++i)
      dp[i][0] = 1;

    for (int k = 1; k <= group.length; ++k) {
      final int g = group[k - 1];
      final int p = profit[k - 1];
      for (int i = n; i >= g; --i)
        for (int j = minProfit; j >= 0; --j) {
          dp[i][j] += dp[i - g][Math.max(0, j - p)];
          dp[i][j] %= kMod;
        }
    }

    return dp[n][minProfit];
  }
}
