class Solution {
 public:
  int regionsBySlashes(vector<string>& grid) {
    const int n = grid.size();
    // g := upscaled grid
    vector<vector<int>> g(n * 3, vector<int>(n * 3));

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == '/') {
          g[i * 3][j * 3 + 2] = 1;
          g[i * 3 + 1][j * 3 + 1] = 1;
          g[i * 3 + 2][j * 3] = 1;
        } else if (grid[i][j] == '\\') {
          g[i * 3][j * 3] = 1;
          g[i * 3 + 1][j * 3 + 1] = 1;
          g[i * 3 + 2][j * 3 + 2] = 1;
        }

    int ans = 0;

    for (int i = 0; i < n * 3; ++i)
      for (int j = 0; j < n * 3; ++j)
        if (g[i][j] == 0) {
          dfs(g, i, j);
          ++ans;
        }

    return ans;
  }

 private:
  void dfs(vector<vector<int>>& g, int i, int j) {
    if (i < 0 || i == g.size() || j < 0 || j == g[0].size())
      return;
    if (g[i][j] != 0)
      return;

    g[i][j] = 2;  // mark 2 as visited
    dfs(g, i + 1, j);
    dfs(g, i - 1, j);
    dfs(g, i, j + 1);
    dfs(g, i, j - 1);
  }
};
