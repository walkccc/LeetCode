class Solution {
  public long maximumStrength(int[] nums, int k) {
    Long[][][] mem = new Long[nums.length][k + 1][2];
    return maximumStrength(nums, 0, k, /*fresh=*/true, mem);
  }

  private static final long kMin = Long.MIN_VALUE / 2;

  // Returns the maximum strength of nums[i..n) with k operations left, where
  // `fresh` means we're starting a new subarray.
  private long maximumStrength(int[] nums, int i, int k, boolean fresh, Long[][][] mem) {
    if (nums.length - i < k)
      return kMin;
    if (k == 0)
      return 0;
    if (i == nums.length)
      return k == 0 ? 0 : kMin;
    if (mem[i][k][fresh ? 1 : 0] != null)
      return mem[i][k][fresh ? 1 : 0];
    // If it's not fresh, we can't skip the current number and consider it as a
    // fresh start, since the case where it's fresh is already covered by
    // `includeAndFreshStart`.
    final long skip = fresh ? maximumStrength(nums, i + 1, k, true, mem) : kMin;
    final long gain = (k % 2 == 0 ? -1 : 1) * 1L * nums[i] * k;
    final long includeAndContinue = maximumStrength(nums, i + 1, k, false, mem) + gain;
    final long includeAndFreshStart = maximumStrength(nums, i + 1, k - 1, true, mem) + gain;
    return mem[i][k][fresh ? 1 : 0] =
               Math.max(skip, Math.max(includeAndContinue, includeAndFreshStart));
  }
}
