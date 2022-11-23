class Solution {
  public int stoneGameVII(int[] stones) {
    final int n = stones.length;
    // dp[i][j] := max score you can get more than your opponent in stones[i..j]
    int[][] dp = new int[n][n];
    int[] prefix = new int[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = stones[i] + prefix[i];

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        final int j = i + d;
        dp[i][j] = Math.max(prefix[j + 1] - prefix[i + 1] - dp[i + 1][j],
                            prefix[j] - prefix[i] - dp[i][j - 1]);
      }

    return dp[0][n - 1];
  }
}
