class Solution {
  public int maxSum(int[] nums, int k, int m) {
    final int n = nums.length;
    int[] prefix = new int[n + 1];
    Integer[][][] mem = new Integer[n][2][k + 1];
    for (int i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + nums[i];
    return maxSum(nums, 0, 0, k, m, prefix, mem);
  }

  private static final int INF = 20_000_000;

  private int maxSum(int[] nums, int i, int ongoing, int k, int m, int[] prefix,
                     Integer[][][] mem) {
    if (k < 0)
      return -INF;
    if (i == nums.length)
      return k == 0 ? 0 : -INF;
    if (mem[i][ongoing][k] != null)
      return mem[i][ongoing][k];
    if (ongoing == 1)
      // 1. End the current subarray (transition to state 0, same index i)
      // 2. Extend the current subarray by picking nums[i] and move to i + 1.
      return mem[i][1][k] = Math.max(maxSum(nums, i, 0, k, m, prefix, mem),
                                     maxSum(nums, i + 1, 1, k, m, prefix, mem) + nums[i]);
    // ongoing == 0
    // 1. Skip nums[i].
    // 2. Pick nums[i..i + m - 1] (only if k > 0 and there're enough elements).
    int res = maxSum(nums, i + 1, 0, k, m, prefix, mem);
    if (i + m <= nums.length) // If we have enough elements for a new segment
      res = Math.max(res,
                     maxSum(nums, i + m, 1, k - 1, m, prefix, mem) + (prefix[i + m] - prefix[i]));

    return mem[i][0][k] = res;
  }
}
