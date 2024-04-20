class Solution {
 public:
  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    // dp[i][j] := the maximum money of cutting i x j piece of wood
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));

    for (const vector<int>& p : prices) {
      const int h = p[0];
      const int w = p[1];
      const int price = p[2];
    }

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        for (int h = 1; h <= i / 2; ++h)
          dp[i][j] = max(dp[i][j], dp[h][j] + dp[i - h][j]);
        for (int w = 1; w <= j / 2; ++w)
          dp[i][j] = max(dp[i][j], dp[i][w] + dp[i][j - w]);
      }

    return dp[m][n];
  }
};
