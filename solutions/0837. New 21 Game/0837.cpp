class Solution {
 public:
  double new21Game(int N, int K, int W) {
    // when the game ends, the point is in [K..K - 1 + W]
    //   P = 1, if N > K - 1 + W
    //   P = 0, if N < K
    if (K == 0 || N >= K + W)
      return 1.0;

    double ans = 0.0;
    vector<double> dp(N + 1);  // dp[i] := P(i)
    dp[0] = 1.0;
    double wSum = dp[0];  // P(i - 1) + P(i - 2) + ... + P(i - W)

    for (int i = 1; i <= N; ++i) {
      // the prob to get point i is
      // P(i) = [P(i - 1) + P(i - 2) + ... + P(i - W)] / W
      dp[i] = wSum / W;
      if (i < K)
        wSum += dp[i];
      else  // the game ends
        ans += dp[i];
      if (i - W >= 0)
        wSum -= dp[i - W];
    }

    return ans;
  }
};
