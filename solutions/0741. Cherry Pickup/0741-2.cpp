class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    const int n = grid.size();
    // dp[x1][y1][x2] := max cherries we could pick from
    // g[0][0] -> g[x1 - 1][y1 - 1] + g[0][0] -> g[x2 - 1][y2 - 1],
    // where y2 = x1 + y1 - x2 (reduce states from 4 to 3)
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
    dp[1][1][1] = grid[0][0];

    for (int x1 = 1; x1 <= n; ++x1)
      for (int y1 = 1; y1 <= n; ++y1)
        for (int x2 = 1; x2 <= n; ++x2) {
          const int y2 = x1 + y1 - x2;
          if (y2 < 1 || y2 > n)
            continue;
          if (grid[x1 - 1][y1 - 1] == -1 || grid[x2 - 1][y2 - 1] == -1)
            continue;
          const int ans = max({dp[x1 - 1][y1][x2], dp[x1 - 1][y1][x2 - 1],
                               dp[x1][y1 - 1][x2], dp[x1][y1 - 1][x2 - 1]});
          if (ans < 0)
            continue;
          dp[x1][y1][x2] = ans + grid[x1 - 1][y1 - 1];
          if (x1 != x2)
            dp[x1][y1][x2] += grid[x2 - 1][y2 - 1];
        }

    return max(0, dp[n][n][n]);
  }
};
