class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    // dp[x][y1][y2] := max cherries we can collect with
    // robot #1 on (x - 1, y1 - 1) and robot #2 on (x - 1, y2 - 1) first
    vector<vector<vector<int>>> dp(m + 2, vector<vector<int>>(n + 2, vector<int>(n + 2)));

    for (int x = m; x >= 1; --x)
      for (int y1 = 1; y1 <= n; ++y1)
        for (int y2 = 1; y2 <= n; ++y2) {
          const int currRow = grid[x - 1][y1 - 1] + (y1 != y2) * grid[x - 1][y2 - 1];
          int& ans = dp[x][y1][y2];
          for (int d1 = -1; d1 <= 1; ++d1)
            for (int d2 = -1; d2 <= 1; ++d2)
              ans = max(ans, currRow + dp[x + 1][y1 + d1][y2 + d2]);
        }

    return dp[1][1][n];
  }
};