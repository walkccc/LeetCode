class Solution {
 public:
  int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i][j] := min cost to reach grid[i][j]
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0] = grid[0];

    for (int i = 1; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j] +
                                       grid[i][j]);

    return *min_element(begin(dp.back()), end(dp.back()));
  }
};
