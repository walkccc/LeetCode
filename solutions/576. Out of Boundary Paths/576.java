class Solution {
  public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    Integer[][][] mem = new Integer[maxMove + 1][m][n];
    return findPaths(m, n, maxMove, startRow, startColumn, mem);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of paths to move the ball at (i, j) out-of-bounds with k
  // moves.
  private int findPaths(int m, int n, int k, int i, int j, Integer[][][] mem) {
    if (i < 0 || i == m || j < 0 || j == n)
      return 1;
    if (k == 0)
      return 0;
    if (mem[k][i][j] != null)
      return mem[k][i][j];
    return mem[k][i][j] = (int) ((findPaths(m, n, k - 1, i + 1, j, mem) * 1L +
                                  findPaths(m, n, k - 1, i - 1, j, mem) +
                                  findPaths(m, n, k - 1, i, j + 1, mem) +
                                  findPaths(m, n, k - 1, i, j - 1, mem)) %
                                 kMod);
  }
}
