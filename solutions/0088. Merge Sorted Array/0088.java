class Solution {
  public void merge(int[] nums1, int m, int[] nums2, int n) {
    int k = m + n - 1;
    --m;
    --n;

    while (n >= 0)
      if (m >= 0 && nums1[m] > nums2[n])
        nums1[k--] = nums1[m--];
      else
        nums1[k--] = nums2[n--];
  }
}