class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    int ans = 0;

    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid.size(); ++j) {
        if (grid[i][j])
          ans += grid[i][j] * 4 + 2;
        if (i > 0)
          ans -= min(grid[i][j], grid[i - 1][j]) * 2;
        if (j > 0)
          ans -= min(grid[i][j], grid[i][j - 1]) * 2;
      }

    return ans;
  }
};
