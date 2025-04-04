class Solution {
  public boolean stoneGame(int[] piles) {
    final int n = piles.length;
    // dp[i][j] := the maximum stones you can get more than your opponent in piles[i..j]
    int[][] dp = new int[n][n];

    for (int i = 0; i < n; ++i)
      dp[i][i] = piles[i];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        dp[i][j] = Math.max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
      }

    return dp[0][n - 1] > 0;
  }
}
