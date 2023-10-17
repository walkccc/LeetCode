class Solution {
 public:
  int maxA(int n) {
    // dp[i] := max 'A' can be printed w/ i pressings
    vector<int> dp(n + 1);

    // 'A' * i
    iota(dp.begin(), dp.end(), 0);

    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= i - 3; ++j)
        dp[i] = max(dp[i], dp[j] * (i - j - 1));

    return dp[n];
  }
};
