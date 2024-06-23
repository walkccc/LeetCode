class Solution {
 public:
  int profitableSchemes(int n, int minProfit, vector<int>& group,
                        vector<int>& profit) {
    constexpr int kMod = 1'000'000'007;
    // dp[k][i][j] := the number of schemes, where the first k crimes are
    // committed by <= i members, generating >= j profits
    vector<vector<vector<int>>> dp(
        group.size() + 1,
        vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));

    // No crimes, no profits, and any number of members.
    for (int i = 0; i <= n; ++i)
      dp[0][i][0] = 1;

    for (int k = 1; k <= group.size(); ++k) {
      const int g = group[k - 1];
      const int p = profit[k - 1];
      for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= minProfit; ++j)
          if (i < g) {
            dp[k][i][j] = dp[k - 1][i][j];
          } else {
            dp[k][i][j] = dp[k - 1][i][j] + dp[k - 1][i - g][max(0, j - p)];
            dp[k][i][j] %= kMod;
          }
    }

    return dp[group.size()][n][minProfit];
  }
};
