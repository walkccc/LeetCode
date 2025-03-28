class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    constexpr int kMod = 1'000'000'007;
    // dp[i][j] := the number of schemes, where <= i members, generating
    // >= j profits
    vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));

    for (int i = 0; i <= n; ++i)
      dp[i][0] = 1;

    for (int k = 1; k <= group.size(); ++k) {
      const int g = group[k - 1];
      const int p = profit[k - 1];
      for (int i = n; i >= g; --i)
        for (int j = minProfit; j >= 0; --j) {
          dp[i][j] += dp[i - g][max(0, j - p)];
          dp[i][j] %= kMod;
        }
    }

    return dp[n][minProfit];
  }
};
