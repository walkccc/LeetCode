class Solution {
 public:
  int numWays(int n, int k) {
    if (n == 0)
      return 0;
    if (n == 1)
      return k;
    if (n == 2)
      return k * k;

    // dp[i] := # of ways to paint n posts with k colors
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = k;
    dp[2] = k * k;

    for (int i = 3; i <= n; ++i)
      dp[i] = (dp[i - 1] + dp[i - 2]) * (k - 1);

    return dp[n];
  }
};
