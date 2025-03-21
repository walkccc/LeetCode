class Solution {
  public int numberOfWays(int n) {
    final int MOD = 1_000_000_007;
    // dp[i] := the number of ways to make the sum of i using coins 1, 2, and 6
    int[] dp = new int[n + 1];
    dp[0] = 1;

    for (final int coin : new int[] {1, 2, 6})
      for (int i = coin; i <= n; ++i)
        dp[i] = (dp[i] + dp[i - coin]) % MOD;

    int ans = dp[n];
    if (n - 4 >= 0)
      ans = (ans + dp[n - 4]) % MOD;
    if (n - 8 >= 0)
      ans = (ans + dp[n - 8]) % MOD;
    return ans;
  }
}
