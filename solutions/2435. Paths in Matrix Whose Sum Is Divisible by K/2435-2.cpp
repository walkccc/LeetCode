class Solution {
 public:
  int numberOfPaths(vector<vector<int>>& grid, int k) {
    constexpr int kMod = 1'000'000'007;
    const int m = grid.size();
    const int n = grid[0].size();
    // dp[i][j][sum] := # of paths till (i, j) where the sum divide by k == sum
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k)));
    dp[0][0][grid[0][0] % k] = 1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        for (int sum = 0; sum < k; ++sum) {
          const int newSum = (sum + grid[i][j]) % k;
          if (i > 0)
            dp[i][j][newSum] += dp[i - 1][j][sum];
          if (j > 0)
            dp[i][j][newSum] += dp[i][j - 1][sum];
          dp[i][j][newSum] %= kMod;
        }

    return dp[m - 1][n - 1][0];
  }
};
