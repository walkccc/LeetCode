class Solution {
 public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    int ans = 0;
    int empty = 1;
    int sx;
    int sy;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 0) {
          ++empty;
        } else if (grid[i][j] == 1) {
          sx = i;
          sy = j;
        } else if (grid[i][j] == 2) {
          ex = i;
          ey = j;
        }
      }

    dfs(grid, empty, sx, sy, ans);

    return ans;
  }

 private:
  int ex;
  int ey;

  void dfs(vector<vector<int>>& grid, int empty, int i, int j, int& ans) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
        grid[i][j] < 0)
      return;
    if (i == ex && j == ey) {
      if (empty == 0) ++ans;
      return;
    }

    grid[i][j] = -2;
    dfs(grid, empty - 1, i + 1, j, ans);
    dfs(grid, empty - 1, i - 1, j, ans);
    dfs(grid, empty - 1, i, j + 1, ans);
    dfs(grid, empty - 1, i, j - 1, ans);
    grid[i][j] = 0;
  }
};