class Solution {
 public:
  int minimumCoins(vector<int>& prices) {
    const int n = prices.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = i + 1; j <= min((i + 1) * 2, n); ++j)
        dp[i] = min(dp[i], prices[i] + dp[j]);

    return dp[0];
  }
};
