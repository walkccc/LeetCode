class Solution {
  public int minProductSum(int[] nums1, int[] nums2) {
    final int n = nums1.length;

    int ans = 0;

    Arrays.sort(nums1);
    Arrays.sort(nums2);

    for (int i = 0; i < n; ++i)
      ans += nums1[i] * nums2[n - 1 - i];

    return ans;
  }
}
