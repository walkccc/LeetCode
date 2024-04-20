class Solution {
  public int deleteGreatestValue(int[][] grid) {
    int ans = 0;

    for (int[] row : grid)
      Arrays.sort(row);

    for (int j = 0; j < grid[0].length; ++j) {
      int maxOfColumn = 0;
      for (int i = 0; i < grid.length; ++i)
        maxOfColumn = Math.max(maxOfColumn, grid[i][j]);
      ans += maxOfColumn;
    }

    return ans;
  }
}
