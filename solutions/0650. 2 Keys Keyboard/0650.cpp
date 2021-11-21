class Solution {
 public:
  int minSteps(int n) {
    if (n <= 1)
      return 0;

    // dp[i] := min steps to get i 'A'
    vector<int> dp(n + 1);

    // copy 'A', then paste 'A' i - 1 times
    iota(begin(dp), end(dp), 0);

    for (int i = 2; i <= n; ++i)
      for (int j = i / 2; j > 2; --j)
        if (i % j == 0) {
          dp[i] = dp[j] + i / j;  // paste dp[j] i / j times
          break;
        }

    return dp[n];
  }
};
