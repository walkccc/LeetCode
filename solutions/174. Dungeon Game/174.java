class Solution {
  public int calculateMinimumHP(int[][] dungeon) {
    final int m = dungeon.length;
    final int n = dungeon[0].length;
    int[][] dp = new int[m + 1][n + 1];
    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j) {
        dp[i][j] = Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
        dp[i][j] = Math.max(dp[i][j], 1);
      }

    return dp[0][0];
  }
}
