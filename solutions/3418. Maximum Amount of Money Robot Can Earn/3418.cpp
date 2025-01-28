class Solution {
 public:
  int maximumAmount(vector<vector<int>>& coins) {
    const int m = coins.size();
    const int n = coins[0].size();
    // dp[i][j][k] := the maximum profit at position (i, j) with k remaining
    // neutralizations
    vector<vector<vector<int>>> dp(
        m, vector<vector<int>>(n, vector<int>(4, -INT_MAX / 2)));

    // Base case: the robot starts at the top-left corner.
    dp[0][0][2] = coins[0][0];
    if (coins[0][0] < 0)
      dp[0][0][1] = 0;  // Neutralize the robber.

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < 3; ++k) {
          if (i > 0)
            dp[i][j][k] = max({dp[i][j][k], dp[i - 1][j][k] + coins[i][j],
                               dp[i - 1][j][k + 1]});
          if (j > 0)
            dp[i][j][k] = max({dp[i][j][k], dp[i][j - 1][k] + coins[i][j],
                               dp[i][j - 1][k + 1]});
        }

    return ranges::max(dp[m - 1][n - 1]);
  }
};
