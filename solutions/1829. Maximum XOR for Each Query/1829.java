class Solution {
  public int[] getMaximumXor(int[] nums, int maximumBit) {
    final int n = nums.length;
    final int max = (1 << maximumBit) - 1;
    int[] ans = new int[n];
    int xors = 0;

    for (int i = 0; i < n; ++i) {
      xors ^= nums[i];
      ans[n - i - 1] = xors ^ max;
    }

    return ans;
  }
}
