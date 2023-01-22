public class Solution {
  public int maxSum(int[][] grid) {
    int ans = 0;

    for (int i = 1; i + 1 < grid.length; ++i)
      for (int j = 1; j + 1 < grid[0].length; ++j)
        ans = Math.max(ans, grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] + grid[i][j] +
                                grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1]);

    return ans;
  }
}
