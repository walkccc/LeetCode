class Solution {
  public int findLength(int[] nums1, int[] nums2) {
    final int m = nums1.length;
    final int n = nums2.length;
    int ans = 0;
    // dp[i][j] := the maximum length of a subarray that appears in both
    // nums1[i..m) and nums2[j..n)
    int[][] dp = new int[m + 1][n + 1];

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j)
        if (nums1[i] == nums2[j]) {
          dp[i][j] = dp[i + 1][j + 1] + 1;
          ans = Math.max(ans, dp[i][j]);
        }

    return ans;
  }
}
