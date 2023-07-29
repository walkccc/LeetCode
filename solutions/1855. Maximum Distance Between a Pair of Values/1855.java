class Solution {
  public int maxDistance(int[] nums1, int[] nums2) {
    int ans = 0;
    int i = 0;
    int j = 0;

    while (i < nums1.length && j < nums2.length)
      if (nums1[i] > nums2[j])
        ++i;
      else
        ans = Math.max(ans, j++ - i);

    return ans;
  }
}
