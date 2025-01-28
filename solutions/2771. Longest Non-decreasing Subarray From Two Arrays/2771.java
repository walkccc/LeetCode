class Solution {
  public int maxNonDecreasingLength(int[] nums1, int[] nums2) {
    int ans = 1;
    int dp1 = 1; // the longest subarray that ends in nums1[i] so far
    int dp2 = 1; // the longest subarray that ends in nums2[i] so far

    for (int i = 1; i < nums1.length; ++i) {
      final int dp11 = nums1[i - 1] <= nums1[i] ? dp1 + 1 : 1;
      final int dp21 = nums2[i - 1] <= nums1[i] ? dp2 + 1 : 1;
      final int dp12 = nums1[i - 1] <= nums2[i] ? dp1 + 1 : 1;
      final int dp22 = nums2[i - 1] <= nums2[i] ? dp2 + 1 : 1;
      dp1 = Math.max(dp11, dp21);
      dp2 = Math.max(dp12, dp22);
      ans = Math.max(ans, Math.max(dp1, dp2));
    }

    return ans;
  }
}
