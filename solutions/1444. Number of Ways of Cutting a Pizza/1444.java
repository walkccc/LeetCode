class Solution {
  public int ways(String[] pizza, int k) {
    final int M = pizza.size();
    final int N = pizza[0].length();
    int[][][] mem = new int[M][N][k];
    int[][] prefix = new int[M + 1][N + 1];

    for (int[][] A : mem)
      Arrays.stream(mem).forEach(B -> Arrays.fill(B, -1));

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        prefix[i + 1][j + 1] = (pizza[i].charAt(j) == 'A' ? 1 : 0) + prefix[i][j + 1] +
                               prefix[i + 1][j] - prefix[i][j];

    return ways(0, 0, k - 1, M, N, prefix, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of ways to cut pizza[m..M)[n..N) with k cuts.
  private int ways(int m, int n, int k, int M, int N, int[][] prefix, int[][][] mem) {
    if (k == 0)
      return hasApple(prefix, m, M, n, N) ? 1 : 0;
    if (mem[m][n][k] != -1)
      return mem[m][n][k];

    mem[m][n][k] = 0;

    for (int i = m + 1; i < M; ++i) // Cut horizontally.
      if (hasApple(prefix, m, i, n, N) && hasApple(prefix, i, M, n, N)) {
        mem[m][n][k] += ways(i, n, k - 1, M, N, prefix, mem);
        mem[m][n][k] %= kMod;
      }

    for (int j = n + 1; j < N; ++j) // Cut vertically.
      if (hasApple(prefix, m, M, n, j) && hasApple(prefix, m, M, j, N)) {
        mem[m][n][k] += ways(m, j, k - 1, M, N, prefix, mem);
        mem[m][n][k] %= kMod;
      }

    return mem[m][n][k];
  }

  // Returns true if pizza[row1..row2)[col1..col2) has apple.
  private boolean hasApple(int[][] prefix, int row1, int row2, int col1, int col2) {
    return (prefix[row2][col2] - prefix[row1][col2] - //
            prefix[row2][col1] + prefix[row1][col1]) > 0;
  }
}
