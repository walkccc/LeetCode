class Solution {
 public:
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0,
                                  int color) {
    dfs(grid, r0, c0, grid[r0][c0]);

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] < 0)
          grid[i][j] = color;

    return grid;
  }

 private:
  void dfs(vector<vector<int>>& grid, int i, int j, int startColor) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] != startColor)
      return;

    grid[i][j] = -startColor;  // mark
    dfs(grid, i + 1, j, startColor);
    dfs(grid, i - 1, j, startColor);
    dfs(grid, i, j + 1, startColor);
    dfs(grid, i, j - 1, startColor);

    // if this cell already on the boarder, it must be painted later
    if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1)
      return;

    if (abs(grid[i + 1][j]) == startColor &&
        abs(grid[i - 1][j]) == startColor &&
        abs(grid[i][j + 1]) == startColor &&
        abs(grid[i][j - 1]) == startColor)
      grid[i][j] = startColor;
  }
};
