class Solution {
  public int removeOnes(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    final int maxMask = 1 << m * n;
    // dp[i] := the minimum number of operations to remove all 1s from the grid,
    // where `i` is the bitmask of the state of the grid
    int[] dp = new int[1 << m * n];
    Arrays.fill(dp, Integer.MAX_VALUE / 2);
    dp[0] = 0;

    for (int mask = 0; mask < maxMask; ++mask)
      for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
          if (grid[i][j] == 1) {
            int nextMask = mask;
            // Set the cells in the same row with 0.
            for (int k = 0; k < n; ++k)
              nextMask &= ~(1 << i * n + k);
            // Set the cells in the same column with 0.
            for (int k = 0; k < m; ++k)
              nextMask &= ~(1 << k * n + j);
            dp[mask] = Math.min(dp[mask], 1 + dp[nextMask]);
          }

    return dp[encode(grid, m, n)];
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
