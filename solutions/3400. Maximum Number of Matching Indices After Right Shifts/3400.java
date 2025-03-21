class Solution {
  public int maximumMatchingIndices(int[] nums1, int[] nums2) {
    final int n = nums1.length;
    int ans = 0;

    for (int shift = 0; shift < n; ++shift) {
      int matches = 0;
      for (int i = 0; i < n; ++i)
        if (nums1[(i + shift) % n] == nums2[i])
          ++matches;
      ans = Math.max(ans, matches);
    }

    return ans;
  }
}
