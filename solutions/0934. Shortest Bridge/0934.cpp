class Solution {
 public:
  int shortestBridge(vector<vector<int>>& grid) {
    markGridTwo(grid);

    for (int color = 2;; ++color)
      for (int i = 0; i < grid.size(); ++i)
        for (int j = 0; j < grid[0].size(); ++j)
          if (grid[i][j] == color)
            if (expand(grid, i + 1, j, color) ||
                expand(grid, i - 1, j, color) ||
                expand(grid, i, j + 1, color) ||
                expand(grid, i, j - 1, color))
              return color - 2;
  }

 private:
  // mark one group to 2s by DFS
  void markGridTwo(vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) {
          markGridTwo(grid, i, j);
          return;
        }
  }

  void markGridTwo(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] != 1)
      return;

    grid[i][j] = 2;
    markGridTwo(grid, i + 1, j);
    markGridTwo(grid, i - 1, j);
    markGridTwo(grid, i, j + 1);
    markGridTwo(grid, i, j - 1);
  }

  // expand from colors' group to 1s' group
  bool expand(vector<vector<int>>& grid, int i, int j, int color) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return false;
    if (grid[i][j] == 0)
      grid[i][j] = color + 1;
    return grid[i][j] == 1;  // we touch the 1s' group!
  }
};
