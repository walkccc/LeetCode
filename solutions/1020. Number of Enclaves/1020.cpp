class Solution {
 public:
  int numEnclaves(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    // Remove the lands connected to the edge.
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i * j == 0 || i == m - 1 || j == n - 1)
          if (grid[i][j] == 1)
            dfs(grid, i, j);

    return accumulate(grid.begin(), grid.end(), 0,
                      [](int subtotal, vector<int>& row) {
      return subtotal + accumulate(row.begin(), row.end(), 0);
    });
  }

 private:
  void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] == 0)
      return;
    grid[i][j] = 0;
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
  };
};
