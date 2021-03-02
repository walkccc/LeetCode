class Solution {
 public:
  vector<int> findBall(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    // dp[i] := status of i-th column
    // 0 := empty, 1 := b0, 2 := b1, ...
    vector<int> dp(n);
    // ans[i] := i-th ball's final position
    vector<int> ans(n, -1);

    for (int i = 0; i < n; ++i)
      dp[i] = i + 1;

    for (int i = 0; i < m; ++i) {
      vector<int> newDp(n);
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
      if (dp[i] > 0)
        ans[dp[i] - 1] = i;

    return ans;
  }
};
