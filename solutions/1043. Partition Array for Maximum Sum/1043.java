class Solution {
  public int maxSumAfterPartitioning(int[] arr, int k) {
    final int n = arr.length;
    int[] dp = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
      int min = Integer.MIN_VALUE;
      for (int j = 1; j <= Math.min(i, k); ++j) {
        min = Math.max(min, arr[i - j]);
        dp[i] = Math.max(dp[i], dp[i - j] + min * j);
      }
    }

    return dp[n];
  }
}
