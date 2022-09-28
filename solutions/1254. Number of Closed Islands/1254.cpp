class Solution {
 public:
  int closedIsland(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    // remove lands connected to edge
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (grid[i][j] == 0)
            dfs(grid, i, j);

    int ans = 0;

    // reduce to 200. Number of Islands
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 0) {
          dfs(grid, i, j);
          ++ans;
        }

    return ans;
  }

 private:
  void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] == 1)
      return;

    grid[i][j] = 1;
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  };
};
