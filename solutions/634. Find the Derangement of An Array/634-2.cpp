class Solution {
 public:
  int findDerangement(int n) {
    constexpr int kMod = 1'000'000'007;
    vector<int> dp(n + 1);

    dp[0] = 1;

    for (int i = 2; i <= n; ++i)
      dp[i] = (i - 1L) * (dp[i - 1] + dp[i - 2]) % kMod;

    return dp[n];
  }
};
