class Solution {
 public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    constexpr int kMod = 1'000'000'007;
    long share = 0;
    // dp[i] := # of people know the secret at day i
    vector<int> dp(n);  // map day i to i + 1
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (i - delay >= 0)
        share += dp[i - delay];
      if (i - forget >= 0)
        share -= dp[i - forget];
      share += kMod;
      share %= kMod;
      dp[i] = share;
    }

    // people before day `n - forget - 1` already forget the secret
    return accumulate(end(dp) - forget, end(dp), 0, [&](int subtotal, int d) {
      return (subtotal + d) % kMod;
    });
  }
};
