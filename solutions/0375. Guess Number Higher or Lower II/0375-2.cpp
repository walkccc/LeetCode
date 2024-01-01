class Solution {
 public:
  int getMoneyAmount(int n) {
    // dp[i][j] := the minimum money you need to guarantee a win of picking i..j
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int d = 1; d < n; ++d)
      for (int i = 1; i + d <= n; ++i) {
        const int j = i + d;
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; ++k)
          dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k);
      }

    return dp[1][n];
  }
};
