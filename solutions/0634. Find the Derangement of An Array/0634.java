class Solution {
  public int findDerangement(int n) {
    dp = new Long[n + 1];
    return (int) find(n);
  }

  private static final int kMod = 1_000_000_007;
  private Long[] dp;

  private long find(int i) {
    if (i == 0)
      return 1;
    if (i == 1)
      return 0;
    if (dp[i] != null)
      return dp[i];
    return dp[i] = (i - 1) * (find(i - 1) + find(i - 2)) % kMod;
  }
}
