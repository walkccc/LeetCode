class Solution {
  public int[] findColumnWidth(int[][] grid) {
    int[] ans = new int[grid[0].length];

    for (int j = 0; j < grid[0].length; ++j) {
      ans[j] = 0;
      for (int i = 0; i < grid.length; ++i)
        ans[j] = Math.max(ans[j], String.valueOf(grid[i][j]).length());
    }

    return ans;
  }
}
