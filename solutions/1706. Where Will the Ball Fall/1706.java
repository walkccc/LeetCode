class Solution {
  public int[] findBall(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i] := status of the i-th column
    // -1 := empty, 0 := b0, 1 := b1, ...
    int[] dp = new int[n];
    // ans[i] := the i-th ball's final position
    int[] ans = new int[n];
    Arrays.fill(ans, -1);

    for (int i = 0; i < n; ++i)
      dp[i] = i;

    for (int i = 0; i < m; ++i) {
      int[] newDp = new int[n];
      Arrays.fill(newDp, -1);
      for (int j = 0; j < n; ++j) {
        // out-of-bounds
        if (j + grid[i][j] < 0 || j + grid[i][j] == n)
          continue;
        // Stuck
        if (grid[i][j] == 1 && grid[i][j + 1] == -1 || grid[i][j] == -1 && grid[i][j - 1] == 1)
          continue;
        newDp[j + grid[i][j]] = dp[j];
      }
      dp = newDp;
    }

    for (int i = 0; i < n; ++i)
      if (dp[i] != -1)
        ans[dp[i]] = i;

    return ans;
  }
}
