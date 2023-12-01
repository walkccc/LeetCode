class Solution {
  public int numEnclaves(int[][] A) {
    final int m = A.length;
    final int n = A[0].length;

    // Remove the lands connected to the edge.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (A[i][j] == 1)
            dfs(A, i, j);

    int ans = 0;

    for (int[] row : A)
      ans += Arrays.stream(row).sum();

    return ans;
  }

  private void dfs(int[][] A, int i, int j) {
    if (i < 0 || i == A.length || j < 0 || j == A[0].length)
      return;
    if (A[i][j] == 0)
      return;

    A[i][j] = 0;
    dfs(A, i + 1, j);
    dfs(A, i - 1, j);
    dfs(A, i, j + 1);
    dfs(A, i, j - 1);
  }
}
