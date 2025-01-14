class Solution {
 public:
  int numSquares(int n) {
    vector<int> dp(n + 1, n);  // 1^2 x n
    dp[0] = 0;                 // no way
    dp[1] = 1;                 // 1^2

    for (int i = 2; i <= n; ++i)
      for (int j = 1; j * j <= i; ++j)
        dp[i] = min(dp[i], dp[i - j * j] + 1);

    return dp[n];
  }
};
