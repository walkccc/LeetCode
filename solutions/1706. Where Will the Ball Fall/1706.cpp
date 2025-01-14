class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i] := status of the i-th column
    // -1 := empty, 0 := b0, 1 := b1, ...
    vector<int> dp(n);
    // ans[i] := the i-th ball's final position
    vector<int> ans(n, -1);

    iota(dp.begin(), dp.end(), 0);

    for (int i = 0; i < m; ++i) {
      vector<int> newDp(n, -1);
      for (int j = 0; j < n; ++j) {
        // out-of-bounds
        if (j + grid[i][j] < 0 || j + grid[i][j] == n)
          continue;
        // Stuck
        if (grid[i][j] == 1 && grid[i][j + 1] == -1 ||
            grid[i][j] == -1 && grid[i][j - 1] == 1)
          continue;
        newDp[j + grid[i][j]] = dp[j];
      }
      dp = std::move(newDp);
    }

    for (int i = 0; i < n; ++i)
      if (dp[i] != -1)
        ans[dp[i]] = i;

    return ans;
  }
};
