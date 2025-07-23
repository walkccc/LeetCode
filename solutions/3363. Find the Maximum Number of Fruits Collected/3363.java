class Solution {
  public int maxCollectedFruits(int[][] fruits) {
    final int n = fruits.length;
    return getTopLeft(fruits) + getTopRight(fruits) + getBottomLeft(fruits) //
        - 2 * fruits[n - 1][n - 1];
  }

  private int getTopLeft(int[][] fruits) {
    final int n = fruits.length;
    int res = 0;
    for (int i = 0; i < n; ++i)
      res += fruits[i][i];
    return res;
  }

  private int getTopRight(int[][] fruits) {
    final int n = fruits.length;
    // dp[i][j] := the number of fruits collected from (0, n - 1) to (i, j)
    int[][] dp = new int[n][n];
    dp[0][n - 1] = fruits[0][n - 1];
    for (int x = 0; x < n; ++x)
      for (int y = 0; y < n; ++y) {
        if (x >= y && !(x == n - 1 && y == n - 1))
          continue;
        for (int[] dir : new int[][] {{1, -1}, {1, 0}, {1, 1}}) {
          final int i = x - dir[0];
          final int j = y - dir[1];
          if (i < 0 || i == n || j < 0 || j == n)
            continue;
          if (i < j && j < n - 1 - i)
            continue;
          dp[x][y] = Math.max(dp[x][y], dp[i][j] + fruits[x][y]);
        }
      }
    return dp[n - 1][n - 1];
  }

  private int getBottomLeft(int[][] fruits) {
    final int n = fruits.length;
    // dp[i][j] := the number of fruits collected from (n - 1, 0) to (i, j)
    int[][] dp = new int[n][n];
    dp[n - 1][0] = fruits[n - 1][0];
    for (int y = 0; y < n; ++y)
      for (int x = 0; x < n; ++x) {
        if (x <= y && !(x == n - 1 && y == n - 1))
          continue;
        for (int[] dir : new int[][] {{-1, 1}, {0, 1}, {1, 1}}) {
          final int i = x - dir[0];
          final int j = y - dir[1];
          if (i < 0 || i == n || j < 0 || j == n)
            continue;
          if (j < i && i < n - 1 - j)
            continue;
          dp[x][y] = Math.max(dp[x][y], dp[i][j] + fruits[x][y]);
        }
      }
    return dp[n - 1][n - 1];
  }
}
