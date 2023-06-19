class Solution {
  public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    this.m = m;
    this.n = n;
    // dp[k][i][j] := # of paths to move the ball (i, j) out of bound w/ k moves
    dp = new Integer[maxMove + 1][m][n];
    return findPaths(maxMove, startRow, startColumn);
  }

  private static final int kMod = 1_000_000_007;
  private int m;
  private int n;
  private Integer[][][] dp;

  private int findPaths(int k, int i, int j) {
    if (i < 0 || i == m || j < 0 || j == n)
      return 1;
    if (k == 0)
      return 0;
    if (dp[k][i][j] != null)
      return dp[k][i][j];
    return dp[k][i][j] = ((findPaths(k - 1, i + 1, j) + findPaths(k - 1, i - 1, j)) % kMod +
                          (findPaths(k - 1, i, j + 1) + findPaths(k - 1, i, j - 1)) % kMod) %
                         kMod;
  }
}
