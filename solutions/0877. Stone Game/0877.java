class Solution {
  public boolean stoneGame(int[] piles) {
    final int n = piles.length;

    int[] dp = Arrays.copyOf(piles, n);

    for (int d = 1; d < n; ++d)
      for (int i = n - d - 1; i >= 0; --i)
        dp[i + d] = Math.max(piles[i] - dp[i + d], piles[i + d] - dp[i + d - 1]);

    return dp[n - 1] > 0;
  }
}