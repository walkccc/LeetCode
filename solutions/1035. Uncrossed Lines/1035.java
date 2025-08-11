class Solution {
  public int maxUncrossedLines(int[] nums1, int[] nums2) {
    final int m = nums1.length;
    final int n = nums2.length;
    int[][] dp = new int[m + 1][n + 1];

    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] = nums1[i - 1] == nums2[j - 1] ? dp[i - 1][j - 1] + 1
                                                : Math.max(dp[i - 1][j], dp[i][j - 1]);

    return dp[m][n];
  }
}
