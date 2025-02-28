class Solution {
  public int maxTrailingZeros(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // leftPrefix2[i][j] := the number of 2 in grid[i][0..j]
    // leftPrefix5[i][j] := the number of 5 in grid[i][0..j]
    // topPrefix2[i][j] := the number of 2 in grid[0..i][j]
    // topPrefix5[i][j] := the number of 5 in grid[0..i][j]
    int[][] leftPrefix2 = new int[m][n];
    int[][] leftPrefix5 = new int[m][n];
    int[][] topPrefix2 = new int[m][n];
    int[][] topPrefix5 = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        leftPrefix2[i][j] = getCount(grid[i][j], 2);
        leftPrefix5[i][j] = getCount(grid[i][j], 5);
        if (j > 0) {
          leftPrefix2[i][j] += leftPrefix2[i][j - 1];
          leftPrefix5[i][j] += leftPrefix5[i][j - 1];
        }
      }

    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i) {
        topPrefix2[i][j] = getCount(grid[i][j], 2);
        topPrefix5[i][j] = getCount(grid[i][j], 5);
        if (i > 0) {
          topPrefix2[i][j] += topPrefix2[i - 1][j];
          topPrefix5[i][j] += topPrefix5[i - 1][j];
        }
      }

    int ans = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        final int curr2 = getCount(grid[i][j], 2);
        final int curr5 = getCount(grid[i][j], 5);
        final int l2 = leftPrefix2[i][j];
        final int l5 = leftPrefix5[i][j];
        final int r2 = leftPrefix2[i][n - 1] - (j > 0 ? leftPrefix2[i][j - 1] : 0);
        final int r5 = leftPrefix5[i][n - 1] - (j > 0 ? leftPrefix5[i][j - 1] : 0);
        final int t2 = topPrefix2[i][j];
        final int t5 = topPrefix5[i][j];
        final int d2 = topPrefix2[m - 1][j] - (i > 0 ? topPrefix2[i - 1][j] : 0);
        final int d5 = topPrefix5[m - 1][j] - (i > 0 ? topPrefix5[i - 1][j] : 0);
        ans = Math.max(ans, Math.max(Math.max(Math.min(l2 + t2 - curr2, l5 + t5 - curr5),
                                              Math.min(r2 + t2 - curr2, r5 + t5 - curr5)),
                                     Math.max(Math.min(l2 + d2 - curr2, l5 + d5 - curr5),
                                              Math.min(r2 + d2 - curr2, r5 + d5 - curr5))));
      }

    return ans;
  }

  private int getCount(int num, int factor) {
    int count = 0;
    while (num % factor == 0) {
      num /= factor;
      ++count;
    }
    return count;
  }
}
