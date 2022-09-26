class Solution {
  public int ways(String[] pizza, int k) {
    final int M = pizza.length;
    final int N = pizza[0].length();
    // dp[m][n][k] := # of ways to cut pizza[m:M][n:N] w/ k cuts
    dp = new int[M][N][k];
    for (int[][] A : dp)
      Arrays.stream(A).forEach(a -> Arrays.fill(a, -1));
    prefix = new int[M + 1][N + 1];

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        prefix[i + 1][j + 1] = (pizza[i].charAt(j) == 'A' ? 1 : 0) + prefix[i][j + 1] +
                               prefix[i + 1][j] - prefix[i][j];

    return ways(0, 0, k - 1, M, N);
  }

  private static final int kMod = 1_000_000_007;
  private int[][][] dp;
  private int[][] prefix;

  // hasApple of pizza[row1..row2)[col1..col2)
  private boolean hasApple(int row1, int row2, int col1, int col2) {
    return (prefix[row2][col2] - prefix[row1][col2] - prefix[row2][col1] + prefix[row1][col1]) > 0;
  }

  private int ways(int m, int n, int k, final int M, final int N) {
    if (k == 0)
      return 1;
    if (dp[m][n][k] >= 0)
      return dp[m][n][k];

    dp[m][n][k] = 0;

    for (int i = m + 1; i < M; ++i) // cut horizontally
      if (hasApple(m, i, n, N) && hasApple(i, M, n, N))
        dp[m][n][k] = (dp[m][n][k] + ways(i, n, k - 1, M, N)) % kMod;

    for (int j = n + 1; j < N; ++j) // cut vertically
      if (hasApple(m, M, n, j) && hasApple(m, M, j, N))
        dp[m][n][k] = (dp[m][n][k] + ways(m, j, k - 1, M, N)) % kMod;

    return dp[m][n][k];
  }
}
