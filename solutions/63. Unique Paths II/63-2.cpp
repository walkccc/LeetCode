class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    vector<long> dp(n);
    dp[0] = 1;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (obstacleGrid[i][j])
          dp[j] = 0;
        else if (j > 0)
          dp[j] += dp[j - 1];

    return dp[n - 1];
  }
};
