class Solution {
  public int minNumber(int[] nums1, int[] nums2) {
    int ans = 89; // the largest num we can have
    for (final int a : nums1)
      for (final int b : nums2)
        ans = Math.min(ans, a == b ? a : Math.min(a, b) * 10 + Math.max(a, b));
    return ans;
  }
}
