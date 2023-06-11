class Solution {
  public int maxIncreaseKeepingSkyline(int[][] grid) {
    final int n = grid.length;
    int ans = 0;
    int[] rowMax = new int[n];
    int[] colMax = new int[n];

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        rowMax[i] = Math.max(rowMax[i], grid[i][j]);
        colMax[j] = Math.max(colMax[j], grid[i][j]);
      }

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        ans += Math.min(rowMax[i], colMax[j]) - grid[i][j];

    return ans;
  }
}
