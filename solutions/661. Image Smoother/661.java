class Solution {
  public int[][] imageSmoother(int[][] M) {
    final int m = M.length;
    final int n = M[0].length;
    int ans[][] = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int ones = 0;
        int count = 0;
        for (int y = Math.max(0, i - 1); y < Math.min(m, i + 2); ++y)
          for (int x = Math.max(0, j - 1); x < Math.min(n, j + 2); ++x) {
            ones += M[y][x];
            ++count;
          }
        ans[i][j] = ones / count;
      }

    return ans;
  }
}
