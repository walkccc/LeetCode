class Solution {
 public:
  int waysToDistribute(int n, int k) {
    constexpr int kMod = 1'000'000'007;
    vector<vector<long>> dp(k + 1, vector<long>(n + 1));

    for (int i = 0; i <= k; ++i)
      dp[i][i] = 1;

    for (int i = 1; i <= k; ++i)
      for (int j = i + 1; j <= n; ++j)
        dp[i][j] = (dp[i - 1][j - 1] + i * dp[i][j - 1]) % kMod;

    return dp[k][n];
  }
};
