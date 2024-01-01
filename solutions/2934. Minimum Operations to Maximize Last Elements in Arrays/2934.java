class Solution {
  public int minOperations(int[] nums1, int[] nums2) {
    final int n = nums1.length;
    final int min = Math.min(nums1[n - 1], nums2[n - 1]);
    final int max = Math.max(nums1[n - 1], nums2[n - 1]);
    // the number of the minimum operations, where nums1[n - 1] is not swapped
    // with nums2[n - 1]
    int dp1 = 0;
    // the number of the minimum operations, where nums1[n - 1] is swapped with
    // nums2[n - 1]
    int dp2 = 0;

    for (int i = 0; i < n; ++i) {
      final int a = nums1[i];
      final int b = nums2[i];
      if (Math.min(a, b) > min)
        return -1;
      if (Math.max(a, b) > max)
        return -1;
      if (a > nums1[n - 1] || b > nums2[n - 1])
        ++dp1;
      if (a > nums2[n - 1] || b > nums1[n - 1])
        ++dp2;
    }

    return Math.min(dp1, dp2);
  }
}
