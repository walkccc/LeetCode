class Solution {
  public int numberOfWays(int n, int x) {
    final int kMod = 1_000_000_007;
    // dp[i] := the number of ways to express i
    int[] dp = new int[n + 1];
    int ax; // a^x

    dp[0] = 1;

    for (int a = 1; (ax = (int) Math.pow(a, x)) <= n; ++a)
      for (int i = n; i >= ax; --i) {
        dp[i] += dp[i - ax];
        dp[i] %= kMod;
      }

    return dp[n];
  }
}
