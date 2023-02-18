class Solution {
  public int totalNQueens(int n) {
    dfs(n, 0, new boolean[n], new boolean[2 * n - 1], new boolean[2 * n - 1]);
    return ans;
  }

  private int ans = 0;

  private void dfs(int n, int i, boolean[] cols, boolean[] diag1, boolean[] diag2) {
    if (i == n) {
      ++ans;
      return;
    }

    for (int j = 0; j < cols.length; ++j) {
      if (cols[j] || diag1[i + j] || diag2[j - i + n - 1])
        continue;
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = true;
      dfs(n, i + 1, cols, diag1, diag2);
      cols[j] = diag1[i + j] = diag2[j - i + n - 1] = false;
    }
  }
}
