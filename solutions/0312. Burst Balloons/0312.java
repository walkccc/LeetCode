class Solution {
  public int maxCoins(int[] nums) {
    final int n = nums.length;

    A = new int[n + 2];

    System.arraycopy(nums, 0, A, 1, n);
    A[0] = 1;
    A[n + 1] = 1;

    // dp[i][j] := maxCoins(A[i..j])
    dp = new int[n + 2][n + 2];
    return maxCoins(1, n);
  }

  private int[][] dp;
  private int[] A;

  private int maxCoins(int i, int j) {
    if (i > j)
      return 0;
    if (dp[i][j] > 0)
      return dp[i][j];

    for (int k = i; k <= j; ++k)
      dp[i][j] = Math.max(dp[i][j],                                 //
                          maxCoins(i, k - 1) + maxCoins(k + 1, j) + //
                              A[i - 1] * A[k] * A[j + 1]);

    return dp[i][j];
  }
}
