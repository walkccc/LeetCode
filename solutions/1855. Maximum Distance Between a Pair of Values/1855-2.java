class Solution {
  public int maxDistance(int[] nums1, int[] nums2) {
    int i = 0;
    int j = 0;

    for (; i < nums1.length && j < nums2.length; ++j)
      if (nums1[i] > nums2[j])
        ++i;

    return i == j ? 0 : j - i - 1;
  }
}
