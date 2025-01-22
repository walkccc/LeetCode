class Solution {
  public int maximumsSplicedArray(int[] nums1, int[] nums2) {
    return Math.max(kadane(nums1, nums2), kadane(nums2, nums1));
  }

  // Returns the maximum gain of swapping some numbers in `nums1` with some numbers in `nums2`.
  private int kadane(int[] nums1, int[] nums2) {
    int gain = 0;
    int maxGain = 0;

    for (int i = 0; i < nums1.length; ++i) {
      gain = Math.max(0, gain + nums2[i] - nums1[i]);
      maxGain = Math.max(maxGain, gain);
    }

    return maxGain + Arrays.stream(nums1).sum();
  }
}
