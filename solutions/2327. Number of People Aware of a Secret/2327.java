class Solution {
  public int peopleAwareOfSecret(int n, int delay, int forget) {
    final int kMod = 1_000_000_007;
    long share = 0;
    // dp[i] := the number of people know the secret at day i
    int[] dp = new int[n]; // Maps day i to i + 1.
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (i - delay >= 0)
        share += dp[i - delay];
      if (i - forget >= 0)
        share -= dp[i - forget];
      share += kMod;
      share %= kMod;
      dp[i] = (int) share;
    }

    // People before day `n - forget - 1` already forget the secret.
    int ans = 0;
    for (int i = n - forget; i < n; ++i)
      ans = (ans + dp[i]) % kMod;
    return ans;
  }
}
