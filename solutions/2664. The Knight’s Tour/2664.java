class Solution {
  public int[][] tourOfKnight(int m, int n, int r, int c) {
    int[][] ans = new int[m][n];
    Arrays.stream(ans).forEach(A -> Arrays.fill(A, -1));
    dfs(m, n, r, c, 0, ans);
    return ans;
  }

  private static final int[][] dirs = {{1, 2},   {2, 1},   {2, -1}, {1, -2},
                                       {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

  private boolean dfs(int m, int n, int i, int j, int step, int[][] ans) {
    if (step == m * n)
      return true;
    if (i < 0 || i >= m || j < 0 || j >= n)
      return false;
    if (ans[i][j] != -1)
      return false;
    ans[i][j] = step;
    for (int[] dir : dirs)
      if (dfs(m, n, i + dir[0], j + dir[1], step + 1, ans))
        return true;
    ans[i][j] = -1;
    return false;
  }
}
