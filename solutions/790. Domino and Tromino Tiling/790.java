class Solution {
  public int numTilings(int n) {
    final int kMod = 1_000_000_007;
    long[] dp = new long[1001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; ++i)
      dp[i] = (2 * dp[i - 1] + dp[i - 3]) % kMod;

    return (int) dp[n];
  }
}
