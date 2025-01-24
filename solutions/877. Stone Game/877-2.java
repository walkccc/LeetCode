class Solution {
  public boolean stoneGame(int[] piles) {
    final int n = piles.length;
    int[] dp = piles.clone();

    for (int d = 1; d < n; ++d)
      for (int j = n - 1; j - d >= 0; --j) {
        final int i = j - d;
        dp[j] = Math.max(piles[i] - dp[j], piles[j] - dp[j - 1]);
      }

    return dp[n - 1] > 0;
  }
}
