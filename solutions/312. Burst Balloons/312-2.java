class Solution {
  public int maxCoins(int[] nums) {
    final int n = nums.length;
    // dp[i][j] := maxCoins(arr[i..j])
    int[][] dp = new int[n + 2][n + 2];
    int[] arr = new int[n + 2];

    System.arraycopy(nums, 0, arr, 1, n);
    arr[0] = 1;
    arr[n + 1] = 1;

    for (int d = 0; d < n; ++d)
      for (int i = 1; i + d <= n; ++i) {
        final int j = i + d;
        for (int k = i; k <= j; ++k)
          dp[i][j] = Math.max(dp[i][j],                     //
                              dp[i][k - 1] + dp[k + 1][j] + //
                                  arr[i - 1] * arr[k] * arr[j + 1]);
      }

    return dp[1][n];
  }
}
