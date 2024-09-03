class Solution {
  public int countSubmatrices(int[][] grid, int k) {
    final int m = grid.length;
    final int n = grid[0].length;
    int ans = 0;
    int[][] prefix = new int[m + 1][n + 1];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        prefix[i + 1][j + 1] = grid[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        if (prefix[i + 1][j + 1] <= k)
          ++ans;
      }

    return ans;
  }
}
