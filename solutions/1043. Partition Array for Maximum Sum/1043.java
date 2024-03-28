class Solution {
  public int maxSumAfterPartitioning(int[] arr, int k) {
    final int n = arr.length;
    int[] dp = new int[n + 1];

    for (int i = 1; i <= n; ++i) {
      int max = Integer.MIN_VALUE;
      for (int j = 1; j <= Math.max(i, k); ++j) {
        max = Math.max(max, arr[i - j]);
        dp[i] = Math.max(dp[i], dp[i - j] + max * j);
      }
    }

    return dp[n];
  }
}
