class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int ans = 0;
    int empty = 1;
    int sx;
    int sy;
    int ex;
    int ey;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 0) {
          ++empty;
        } else if (grid[i][j] == 1) {
          sx = i;
          sy = j;
        } else if (grid[i][j] == 2) {
          ex = i;
          ey = j;
        }

    dfs(grid, empty, sx, sy, ex, ey, ans);

    return ans;
  }

 private:
  void dfs(vector<vector<int>>& grid, int empty, int i, int j, int ex, int ey,
           int& ans) {
    if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size())
      return;
    if (grid[i][j] < 0)
      return;
    if (i == ex && j == ey) {
      if (empty == 0)
        ++ans;
      return;
    }

    grid[i][j] = -2;
    dfs(grid, empty - 1, i + 1, j, ex, ey, ans);
    dfs(grid, empty - 1, i - 1, j, ex, ey, ans);
    dfs(grid, empty - 1, i, j + 1, ex, ey, ans);
    dfs(grid, empty - 1, i, j - 1, ex, ey, ans);
    grid[i][j] = 0;
  }
};
