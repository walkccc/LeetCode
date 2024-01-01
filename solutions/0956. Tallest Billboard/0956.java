class Solution {
  public int tallestBillboard(int[] rods) {
    final int n = rods.length;
    final int sum = Arrays.stream(rods).sum();
    // dp[i][j] := the maximum min-height of using rods[0..i) to pile two piles
    // that have height difference j
    int[][] dp = new int[n + 1][sum + 1];
    Arrays.stream(dp).forEach(row -> Arrays.fill(row, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      final int h = rods[i - 1];
      for (int j = 0; j <= sum - h; ++j) {
        if (dp[i - 1][j] < 0)
          continue;
        // Don't use rods[i - 1].
        dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
        // Put on the taller pile.
        dp[i][j + h] = Math.max(dp[i][j + h], dp[i - 1][j]);
        // Put on the shorter pile.
        dp[i][Math.abs(j - h)] = Math.max(dp[i][Math.abs(j - h)], dp[i - 1][j] + Math.min(j, h));
      }
    }

    return dp[n][0];
  }
}
