class Solution {
 public:
  bool hasValidPath(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // g := upscaled grid
    vector<vector<bool>> g(m * 3, vector<bool>(n * 3));

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

 private:
  bool dfs(vector<vector<bool>>& g, int i, int j) {
    if (i < 0 || i == g.size() || j < 0 || j == g[0].size())
      return false;
    if (!g[i][j])  // There's no path here.
      return false;
    if (i == g.size() - 2 && j == g[0].size() - 2)
      return true;

    g[i][j] = false;  // Mark as visited.
    return dfs(g, i + 1, j) || dfs(g, i - 1, j) || dfs(g, i, j + 1) ||
           dfs(g, i, j - 1);
  }
};
