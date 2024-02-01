class Solution {
  public boolean canDivideIntoSubsequences(int[] nums, int k) {
    // Find the number with the maxFreq, we need at least maxFreq * k elements
    // e.g. nums = [1, 2, 2, 3, 4], we have maxFreq = 2 (two 2s), so we have to
    // Split nums into two subsequences say k = 3, the minimum length of nums is 2 x
    // 3 = 6, which is impossible if nums.size() = 5
    final int n = nums.length;
    int freq = 1;
    int maxFreq = 1;

    for (int i = 1; i < n; ++i) {
      freq = nums[i - 1] < nums[i] ? 1 : ++freq;
      maxFreq = Math.max(maxFreq, freq);
    }

    return n >= maxFreq * k;
  }
}
