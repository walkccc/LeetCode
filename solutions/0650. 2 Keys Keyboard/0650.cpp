class Solution {
 public:
  int minSteps(int n) {
    if (n <= 1)
      return 0;

    // dp[i] := the minimum steps to get i 'A's
    vector<int> dp(n + 1);

    // Copy 'A', then paste 'A' i - 1 times.
    iota(dp.begin(), dp.end(), 0);

    for (int i = 2; i <= n; ++i)
      for (int j = i / 2; j > 2; --j)
        if (i % j == 0) {
          dp[i] = dp[j] + i / j;  // Paste dp[j] i / j times.
          break;
        }

    return dp[n];
  }
};
