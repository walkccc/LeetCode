class Solution {
  public int minSwaps(int[] nums) {
    final int n = nums.length;
    final int k = (int) Arrays.stream(nums).filter(a -> a == 1).count();
    int ones = 0;    // the number of ones in the window
    int maxOnes = 0; // the maximum number of ones in the window

    for (int i = 0; i < n * 2; ++i) {
      if (i >= k && nums[(i - k) % n] == 1)
        --ones;
      if (nums[i % n] == 1)
        ++ones;
      maxOnes = Math.max(maxOnes, ones);
    }

    return k - maxOnes;
  }
}
