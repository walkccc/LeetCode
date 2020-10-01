class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    int ans = 0;

    function<int(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || i == m || j < 0 || j == n) return 0;
      if (grid[i][j] != 1) return 0;

      grid[i][j] = 2;

      return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1);
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = max(ans, dfs(i, j));

    return ans;
  }
};