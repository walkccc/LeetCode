class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int length = 2; length <= n; ++length)
      for (int i = 1; i + length - 1 <= n; ++i) {
        const int j = i + length - 1;
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; ++k)
          dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
      }

    return dp[1][n];
  }
};