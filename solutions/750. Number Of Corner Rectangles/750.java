class Solution {
  public int countCornerRectangles(int[][] grid) {
    int ans = 0;

    for (int row1 = 0; row1 < grid.length - 1; ++row1)
      for (int row2 = row1 + 1; row2 < grid.length; ++row2) {
        int count = 0;
        for (int j = 0; j < grid[0].length; ++j)
          if (grid[row1][j] == 1 && grid[row2][j] == 1)
            ++count;
        ans += count * (count - 1) / 2;
      }

    return ans;
  }
}
