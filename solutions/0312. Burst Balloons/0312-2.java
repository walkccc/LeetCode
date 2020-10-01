class Solution {
  public int maxCoins(int[] nums) {
    final int n = nums.length;

    A = new int[n + 2];
    System.arraycopy(nums, 0, A, 1, n);
    A[0] = 1;
    A[n + 1] = 1;

    memo = new int[n + 2][n + 2];

    return dp(1, n);
  }

  private int[] A;
  private int[][] memo;

  private int dp(int i, int j) {
    if (i > j)
      return 0;
    int ans = memo[i][j];
    if (ans > 0)
      return ans;

    for (int k = i; k <= j; ++k)
      ans = Math.max(ans, dp(i, k - 1) + dp(k + 1, j) + A[i - 1] * A[k] * A[j + 1]);

    return memo[i][j] = ans;
  }
}