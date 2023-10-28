class Solution {
 public:
  int countPaths(vector<vector<int>>& grid) {
    m = grid.size();
    n = grid[0].size();
    int ans = 0;
    // dp[i][j] := # of increasing paths starting from (i, j)
    dp.resize(m, vector<int>(n, -1));

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        ans += dfs(grid, i, j);
        ans %= kMod;
      }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;
  const vector<int> dirs{0, 1, 0, -1, 0};
  int m;
  int n;
  vector<vector<int>> dp;

  int dfs(const vector<vector<int>>& grid, int i, int j) {
    if (dp[i][j] != -1)
      return dp[i][j];

    dp[i][j] = 1;  // Current cell contributes 1 length

    for (int k = 0; k < 4; ++k) {
      const int x = i + dirs[k];
      const int y = j + dirs[k + 1];
      if (x < 0 || x == m || y < 0 || y == n)
        continue;
      if (grid[x][y] <= grid[i][j])
        continue;
      dp[i][j] += dfs(grid, x, y);
      dp[i][j] %= kMod;
    }

    return dp[i][j];
  }
};
