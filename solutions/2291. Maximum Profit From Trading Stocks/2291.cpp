class Solution {
 public:
  int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
    const int n = present.size();
    // dp[i][j] := max profit of buying present[0..i) with j budget
    vector<vector<int>> dp(n + 1, vector<int>(budget + 1));

    for (int i = 1; i <= n; ++i) {
      const int profit = future[i - 1] - present[i - 1];
      for (int j = 0; j <= budget; ++j)
        if (j < present[i - 1])
          dp[i][j] = dp[i - 1][j];
        else
          dp[i][j] = max(dp[i - 1][j], profit + dp[i - 1][j - present[i - 1]]);
    }

    return dp[n][budget];
  }
};
