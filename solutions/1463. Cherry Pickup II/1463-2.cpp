class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[x][y1][y2] := the maximum cherries we can collect, where the robot #1
    // is on (x, y1) and the robot #2 is on (x, y2)
    vector<vector<vector<int>>> dp(m + 1,
                                   vector<vector<int>>(n, vector<int>(n)));

    for (int x = m - 1; x >= 0; --x)
      for (int y1 = 0; y1 < n; ++y1)
        for (int y2 = 0; y2 < n; ++y2) {
          const int currRow = grid[x][y1] + (y1 != y2) * grid[x][y2];
          for (int d1 = max(0, y1 - 1); d1 < min(n, y1 + 2); ++d1)
            for (int d2 = max(0, y2 - 1); d2 < min(n, y2 + 2); ++d2)
              dp[x][y1][y2] = max(dp[x][y1][y2], currRow + dp[x + 1][d1][d2]);
        }

    return dp[0][0][n - 1];
  }
};
