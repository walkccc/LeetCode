class Solution {
 public:
  int maxA(int N) {
    // dp[i] := max 'A' can be printed w/ i pressings
    vector<int> dp(N + 1);

    // 'A' * i
    iota(begin(dp), end(dp), 0);

    for (int i = 0; i <= N; ++i)
      for (int j = 0; j <= i - 3; ++j)
        dp[i] = max(dp[i], dp[j] * (i - j - 1));

    return dp[N];
  }
};
