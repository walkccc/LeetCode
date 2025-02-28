class Solution {
 public:
  int maxMoves(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    int ans = 0;
    // dp[i][j] := the maximum number of moves you can perform from (i, j)
    vector<vector<int>> dp(m, vector<int>(n));

    for (int j = n - 2; j >= 0; --j)
      for (int i = 0; i < m; ++i) {
        if (grid[i][j + 1] > grid[i][j])
          dp[i][j] = 1 + dp[i][j + 1];
        if (i > 0 && grid[i - 1][j + 1] > grid[i][j])
          dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j + 1]);
        if (i + 1 < m && grid[i + 1][j + 1] > grid[i][j])
          dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j + 1]);
      }

    for (int i = 0; i < m; ++i)
      ans = max(ans, dp[i][0]);

    return ans;
  }
};
