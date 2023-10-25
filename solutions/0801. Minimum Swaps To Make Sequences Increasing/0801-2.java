class Solution {
  public int minSwap(int[] nums1, int[] nums2) {
    int keepAt = 0;
    int swapAt = 1;
    int prevKeepAt = 0;
    int prevSwapAt = 1;

    for (int i = 1; i < nums1.length; ++i) {
      keepAt = Integer.MAX_VALUE;
      swapAt = Integer.MAX_VALUE;
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        keepAt = prevKeepAt;
        swapAt = prevSwapAt + 1;
      }
      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        keepAt = Math.min(keepAt, prevSwapAt);
        swapAt = Math.min(swapAt, prevKeepAt + 1);
      }
      prevKeepAt = keepAt;
      prevSwapAt = swapAt;
    }

    return Math.min(keepAt, swapAt);
  }
}
