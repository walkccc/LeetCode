class Solution {
 public:
  int numberOfWays(int n, int x) {
    constexpr int kMod = 1'000'000'007;
    // dp[i] := the number of ways to express i
    vector<int> dp(n + 1);
    int ax;  // a^x

    dp[0] = 1;

    for (int a = 1; (ax = pow(a, x)) <= n; ++a)
      for (int i = n; i >= ax; --i) {
        dp[i] += dp[i - ax];
        dp[i] %= kMod;
      }

    return dp[n];
  }
};
