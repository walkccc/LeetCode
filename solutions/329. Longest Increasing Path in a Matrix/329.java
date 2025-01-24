class Solution {
  public int longestIncreasingPath(int[][] matrix) {
    final int m = matrix.length;
    final int n = matrix[0].length;
    int ans = 0;
    // mem[i][j] := the LIP starting from matrix[i][j]
    int[][] mem = new int[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = Math.max(ans, dfs(matrix, i, j, Integer.MIN_VALUE, mem));

    return ans;
  }

  private int dfs(int[][] matrix, int i, int j, int prev, int[][] mem) {
    if (i < 0 || i == matrix.length || j < 0 || j == matrix[0].length)
      return 0;
    if (matrix[i][j] <= prev)
      return 0;
    if (mem[i][j] > 0)
      return mem[i][j];

    final int curr = matrix[i][j];
    final int a = dfs(matrix, i + 1, j, curr, mem);
    final int b = dfs(matrix, i - 1, j, curr, mem);
    final int c = dfs(matrix, i, j + 1, curr, mem);
    final int d = dfs(matrix, i, j - 1, curr, mem);
    return mem[i][j] = 1 + Math.max(Math.max(a, b), Math.max(c, d));
  }
}
