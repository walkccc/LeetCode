class Solution {
  public boolean hasValidPath(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;
    // g := upscaled grid
    boolean[][] g = new boolean[m * 3][n * 3];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        switch (grid[i][j]) {
          case 1:
            g[i * 3 + 1][j * 3 + 0] = true;
            g[i * 3 + 1][j * 3 + 1] = true;
            g[i * 3 + 1][j * 3 + 2] = true;
            break;
          case 2:
            g[i * 3 + 0][j * 3 + 1] = true;
            g[i * 3 + 1][j * 3 + 1] = true;
            g[i * 3 + 2][j * 3 + 1] = true;
            break;
          case 3:
            g[i * 3 + 1][j * 3 + 0] = true;
            g[i * 3 + 1][j * 3 + 1] = true;
            g[i * 3 + 2][j * 3 + 1] = true;
            break;
          case 4:
            g[i * 3 + 1][j * 3 + 1] = true;
            g[i * 3 + 1][j * 3 + 2] = true;
            g[i * 3 + 2][j * 3 + 1] = true;
            break;
          case 5:
            g[i * 3 + 0][j * 3 + 1] = true;
            g[i * 3 + 1][j * 3 + 0] = true;
            g[i * 3 + 1][j * 3 + 1] = true;
            break;
          case 6:
            g[i * 3 + 0][j * 3 + 1] = true;
            g[i * 3 + 1][j * 3 + 1] = true;
            g[i * 3 + 1][j * 3 + 2] = true;
            break;
        }

    return dfs(g, 1, 1);
  }

  private boolean dfs(boolean[][] g, int i, int j) {
    if (i < 0 || i == g.length || j < 0 || j == g[0].length)
      return false;
    if (!g[i][j]) // no path here
      return false;
    if (i == g.length - 2 && j == g[0].length - 2)
      return true;

    g[i][j] = false; // mark as visited
    return dfs(g, i + 1, j) || dfs(g, i - 1, j) || dfs(g, i, j + 1) || dfs(g, i, j - 1);
  }
}
