class Solution {
  public int findDerangement(int n) {
    final int kMod = 1_000_000_007;
    int[] dp = new int[n + 1];

    dp[0] = 1;

    for (int i = 2; i <= n; ++i)
      dp[i] = (int) ((i - 1L) * (dp[i - 1] + dp[i - 2]) % kMod);

    return dp[n];
  }
}
