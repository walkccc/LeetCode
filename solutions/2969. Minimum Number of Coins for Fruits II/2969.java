class Solution {
  // Same as 2944. Minimum Number of Coins for Fruits
  public int minimumCoins(int[] prices) {
    final int n = prices.length;
    int[] dp = new int[n + 1];
    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; --i)
      for (int j = i + 1; j <= Math.min((i + 1) * 2, n); ++j)
        dp[i] = Math.min(dp[i], prices[i] + dp[j]);

    return dp[0];
  }
}
