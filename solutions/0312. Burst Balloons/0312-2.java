class Solution {
  public int maxCoins(int[] nums) {
    final int n = nums.length;
    int[] A = new int[n + 2];
    System.arraycopy(nums, 0, A, 1, n);
    A[0] = 1;
    A[n + 1] = 1;

    // dp[i][j] := maxCoins(A[i..j])
    int[][] dp = new int[n + 2][n + 2];

    for (int d = 0; d < n; ++d)
      for (int i = 1; i + d <= n; ++i) {
        final int j = i + d;
        for (int k = i; k <= j; ++k)
          dp[i][j] = Math.max(dp[i][j],                     //
                              dp[i][k - 1] + dp[k + 1][j] + //
                                  A[i - 1] * A[k] * A[j + 1]);
      }

    return dp[1][n];
  }
}
