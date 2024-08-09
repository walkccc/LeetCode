class Solution {
  public int splitArray(int[] nums, int k) {
    final int n = nums.length;
    int[][] mem = new int[n + 1][k + 1];
    int[] prefix = new int[n + 1];
    Arrays.stream(mem).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = nums[i] + prefix[i];

    return splitArray(nums, n, k, prefix, mem);
  }

  // Returns the minimum of the maximum sum to split the first i numbers into k
  // groups.
  private int splitArray(int[] nums, int i, int k, int[] prefix, int[][] mem) {
    if (k == 1)
      return prefix[i];
    if (mem[i][k] < Integer.MAX_VALUE)
      return mem[i][k];

    // Try all the possible partitions.
    for (int j = k - 1; j < i; ++j)
      mem[i][k] = Math.min(mem[i][k],                                        //
                           Math.max(splitArray(nums, j, k - 1, prefix, mem), //
                                    prefix[i] - prefix[j]));

    return mem[i][k];
  }
}
