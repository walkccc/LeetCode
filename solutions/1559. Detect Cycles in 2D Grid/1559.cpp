class Solution {
 public:
  bool containsCycle(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    vector<vector<bool>> seen(m, vector<bool>(n));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (seen[i][j])
          continue;
        if (dfs(grid, i, j, -1, -1, grid[i][j], seen))
          return true;
      }

    return false;
  }

 private:
  static constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  bool dfs(const vector<vector<char>>& grid, int i, int j, int prevI, int prevJ,
           char c, vector<vector<bool>>& seen) {
    seen[i][j] = true;

    for (const auto& [dx, dy] : kDirs) {
      const int x = i + dx;
      const int y = j + dy;
      if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
        continue;
      if (x == prevI && y == prevJ)
        continue;
      if (grid[x][y] != c)
        continue;
      if (seen[x][y])
        return true;
      if (dfs(grid, x, y, i, j, c, seen))
        return true;
    }

    return false;
  }
};
