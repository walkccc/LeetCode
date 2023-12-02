class Solution {
  public int removeOnes(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // dp[i] := the minimum number of operations to remove all 1s from the grid,
    // where bitmask i represents the state of the grid
    dp = new int[1 << m * n];
    Arrays.fill(dp, Integer.MAX_VALUE);
    return dfs(encode(grid, m, n), m, n);
  }

  private int[] dp;

  private int dfs(int mask, int m, int n) {
    if (mask == 0)
      return 0;
    if (dp[mask] < Integer.MAX_VALUE)
      return dp[mask];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if ((mask >> i * n + j & 1) == 1) { // grid[i][j] == 1
          int nextMask = mask;
          // Set the cells in the same row with 0.
          for (int k = 0; k < n; ++k)
            nextMask &= ~(1 << i * n + k);
          // Set the cells in the same column with 0.
          for (int k = 0; k < m; ++k)
            nextMask &= ~(1 << k * n + j);
          dp[mask] = Math.min(dp[mask], 1 + dfs(nextMask, m, n));
        }

    return dp[mask];
  }

  private int encode(int[][] grid, int m, int n) {
    int encoded = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          encoded |= 1 << i * n + j;
    return encoded;
  }
}
