class Solution {
 public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int ans = 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        ans = max(ans, dfs(grid, i, j));

    return ans;
  }

 private:
  int dfs(vector<vector<int>>& grid, int i, int j) {
    if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
      return 0;
    if (grid[i][j] == 0)
      return 0;

    const int gold = grid[i][j];
    grid[i][j] = 0;  // Mark as visited.
    const int maxPath = max({dfs(grid, i + 1, j), dfs(grid, i - 1, j),
                             dfs(grid, i, j + 1), dfs(grid, i, j - 1)});
    grid[i][j] = gold;
    return gold + maxPath;
  }
};
