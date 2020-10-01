class Solution {
 public:
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0,
                                  int color) {
    dfs(grid, r0, c0, grid[r0][c0]);

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] < 0) grid[i][j] = color;

    return grid;
  }

 private:
  void dfs(vector<vector<int>>& grid, int i, int j, int originalColor) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] != originalColor)
      return;

    grid[i][j] = -originalColor;
    dfs(grid, i + 1, j, originalColor);
    dfs(grid, i - 1, j, originalColor);
    dfs(grid, i, j + 1, originalColor);
    dfs(grid, i, j - 1, originalColor);

    if (i > 0 && i + 1 < grid.size() && j > 0 && j + 1 < grid[0].size() &&
        abs(grid[i + 1][j]) == originalColor &&
        abs(grid[i - 1][j]) == originalColor &&
        abs(grid[i][j + 1]) == originalColor &&
        abs(grid[i][j - 1]) == originalColor)
      grid[i][j] = originalColor;
  }
};