class Solution {
  public int maximumAmount(int[][] coins) {
    final int m = coins.length;
    final int n = coins[0].length;
    // dp[i][j][k] := the maximum profit at position (i, j) with k remaining neutralizations
    int[][][] dp = new int[m][n][4];
    Arrays.stream(dp).forEach(
        A -> Arrays.stream(A).forEach(B -> Arrays.fill(B, Integer.MIN_VALUE / 2)));

    // Base case: the robot starts at the top-left corner.
    dp[0][0][2] = coins[0][0];
    if (coins[0][0] < 0)
      dp[0][0][1] = 0; // Neutralize the robber.

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        for (int k = 0; k < 3; k++) {
          if (i > 0)
            dp[i][j][k] =
                Math.max(dp[i][j][k], Math.max(dp[i - 1][j][k] + coins[i][j], dp[i - 1][j][k + 1]));
          if (j > 0)
            dp[i][j][k] =
                Math.max(dp[i][j][k], Math.max(dp[i][j - 1][k] + coins[i][j], dp[i][j - 1][k + 1]));
        }

    return Arrays.stream(dp[m - 1][n - 1]).max().getAsInt();
  }
}
