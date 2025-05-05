class Solution {
  public int minLargest(int[] nums1, int[] nums2) {
    final int m = nums1.length;
    final int n = nums2.length;
    // dp[i][j] := the minimum largest number for the first i nums1 and the
    // first j nums2
    int[][] dp = new int[m + 1][n + 1];

    Arrays.stream(dp).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));
    dp[0][0] = 0;

    for (int i = 0; i <= m; ++i)
      for (int j = 0; j <= n; ++j) {
        if (i > 0)
          dp[i][j] = Math.min(dp[i][j], f(dp[i - 1][j], nums1[i - 1]));
        if (j > 0)
          dp[i][j] = Math.min(dp[i][j], f(dp[i][j - 1], nums2[j - 1]));
      }

    return dp[m][n];
  }

  // Returns the next number to fill in the array based on the previous number
  // and the current number.
  private int f(int prev, int num) {
    return prev + (prev % 2 == num ? 2 : 1);
  }
}
