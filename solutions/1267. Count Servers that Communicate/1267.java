class Solution {
  public int countServers(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    int[] rows = new int[m];
    int[] cols = new int[n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          ++rows[i];
          ++cols[j];
        }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1))
          ++ans;

    return ans;
  }
}
