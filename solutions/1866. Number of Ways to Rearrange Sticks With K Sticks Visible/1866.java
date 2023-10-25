class Solution {
  public int rearrangeSticks(int n, int k) {
    if (n == k)
      return 1;
    if (k == 0)
      return 0;
    if (dp[n][k] != 0)
      return dp[n][k];
    return dp[n][k] = (int) (((long) rearrangeSticks(n - 1, k - 1) +
                              (long) rearrangeSticks(n - 1, k) * (n - 1)) %
                             kMod);
  }

  private static final int kMod = 1_000_000_007;
  private int[][] dp = new int[1001][1001];
}
