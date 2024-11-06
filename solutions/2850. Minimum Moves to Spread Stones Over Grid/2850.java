class Solution {
  public int minimumMoves(int[][] grid) {
    int zeroCount = 0;
    for (int[] row : grid)
      for (int cell : row)
        if (cell == 0)
          ++zeroCount;
    if (zeroCount == 0)
      return 0;

    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j)
        if (grid[i][j] == 0)
          for (int x = 0; x < 3; ++x)
            for (int y = 0; y < 3; ++y)
              if (grid[x][y] > 1) {
                --grid[x][y];
                ++grid[i][j];
                ans = Math.min(ans, Math.abs(x - i) + Math.abs(y - j) + minimumMoves(grid));
                ++grid[x][y];
                --grid[i][j];
              }

    return ans;
  }
}
