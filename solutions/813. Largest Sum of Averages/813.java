class Solution {
  public double largestSumOfAverages(int[] nums, int k) {
    final int n = nums.length;
    double[][] mem = new double[n + 1][k + 1];
    double[] prefix = new double[n + 1];

    for (int i = 0; i < n; i++)
      prefix[i + 1] = prefix[i] + nums[i];

    return largestSumOfAverages(nums, n, k, prefix, mem);
  }

  // Returns the maximum score to partition the first i numbers into k groups.
  private double largestSumOfAverages(int[] nums, int i, int k, double[] prefix, double[][] mem) {
    if (k == 1)
      return prefix[i] / i;
    if (mem[i][k] > 0)
      return mem[i][k];

    // Try all the possible partitions.
    for (int j = k - 1; j < i; ++j)
      mem[i][k] = Math.max(mem[i][k], largestSumOfAverages(nums, j, k - 1, prefix, mem) +
                                          (prefix[i] - prefix[j]) / (i - j));

    return mem[i][k];
  }
}
