class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i] := status of i-th column
    // -1 := empty, 0 := b0, 1 := b1, ...
    vector<int> dp(n);
    // ans[i] := i-th ball's final position
    vector<int> ans(n, -1);

    iota(begin(dp), end(dp), 0);

    for (int i = 0; i < m; ++i) {
      vector<int> newDp(n, -1);
      for (int j = 0; j < n; ++j) {
        // out of bound
        if (j + grid[i][j] < 0 || j + grid[i][j] == n)
          continue;
        // stuck
        if (grid[i][j] == 1 && grid[i][j + 1] == -1 ||
            grid[i][j] == -1 && grid[i][j - 1] == 1)
          continue;
        newDp[j + grid[i][j]] = dp[j];
      }
      dp = move(newDp);
    }

    for (int i = 0; i < n; ++i)
      if (dp[i] != -1)
        ans[dp[i]] = i;

    return ans;
  }
};
