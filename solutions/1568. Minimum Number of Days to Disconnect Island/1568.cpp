class Solution {
 public:
  int minDays(vector<vector<int>>& grid) {
    if (disconnected(grid))
      return 0;

    // Try to remove 1 land.
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          if (disconnected(grid))
            return 1;
          grid[i][j] = 1;
        }

    // Remove 2 lands.
    return 2;
  }

 private:
  const vector<int> dirs{0, 1, 0, -1, 0};

  bool disconnected(const vector<vector<int>>& grid) {
    int islandsCount = 0;
    vector<vector<bool>> seen(grid.size(), vector<bool>(grid[0].size()));
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 0 || seen[i][j])
          continue;
        if (++islandsCount > 1)
          return true;
        dfs(grid, i, j, seen);
      }
    return islandsCount != 1;
  }

  void dfs(const vector<vector<int>>& grid, int i, int j,
           vector<vector<bool>>& seen) {
    seen[i][j] = true;
    for (int k = 0; k < 4; ++k) {
      const int x = i + dirs[k];
      const int y = j + dirs[k + 1];
      if (x < 0 || x == grid.size() || y < 0 || y == grid[0].size())
        continue;
      if (grid[x][y] == 0 || seen[x][y])
        continue;
      dfs(grid, x, y, seen);
    }
  }
};
