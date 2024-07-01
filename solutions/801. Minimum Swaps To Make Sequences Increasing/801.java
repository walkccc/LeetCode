class Solution {
  public int minSwap(int[] nums1, int[] nums2) {
    final int n = nums1.length;
    int[] keepAt = new int[n];
    int[] swapAt = new int[n];
    Arrays.fill(keepAt, Integer.MAX_VALUE);
    Arrays.fill(swapAt, Integer.MAX_VALUE);
    keepAt[0] = 0;
    swapAt[0] = 1;

    for (int i = 1; i < n; ++i) {
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        keepAt[i] = keepAt[i - 1];
        swapAt[i] = swapAt[i - 1] + 1;
      }
      if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
        keepAt[i] = Math.min(keepAt[i], swapAt[i - 1]);
        swapAt[i] = Math.min(swapAt[i], keepAt[i - 1] + 1);
      }
    }

    return Math.min(keepAt[n - 1], swapAt[n - 1]);
  }
}
