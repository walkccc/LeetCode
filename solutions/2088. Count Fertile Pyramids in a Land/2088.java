class Solution {
  public int countPyramids(int[][] grid) {
    return count(reversed(grid)) + count(grid);
  }

  // dp[i][j] := max height of the pyramid for which it is the apex
  private int count(int[][] dp) {
    int ans = 0;
    for (int i = dp.length - 2; i >= 0; --i)
      for (int j = 1; j + 1 < dp[0].length; ++j)
        if (dp[i][j] == 1) {
          dp[i][j] = Math.min(dp[i + 1][j - 1], Math.min(dp[i + 1][j], dp[i + 1][j + 1])) + 1;
          ans += dp[i][j] - 1;
        }
    return ans;
  }

  private int[][] reversed(int[][] grid) {
    int[][] A = new int[grid.length][];
    for (int i = 0; i < grid.length; ++i)
      A[i] = grid[grid.length - i - 1].clone();
    return A;
  }
}
