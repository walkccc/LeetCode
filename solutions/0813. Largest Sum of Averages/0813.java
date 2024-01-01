class Solution {
  public double largestSumOfAverages(int[] nums, int k) {
    final int n = nums.length;
    // dp[i][k] := the maximum score to partition the first i nums into k groups
    dp = new double[n + 1][k + 1];
    prefix = new double[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = nums[i] + prefix[i];

    return largestSumOfAverages(nums, n, k);
  }

  private double[][] dp;
  private double[] prefix;

  private double largestSumOfAverages(int[] nums, int i, int k) {
    if (k == 1)
      return prefix[i] / i;
    if (dp[i][k] > 0.0)
      return dp[i][k];

    // Try all the possible partitions.
    for (int j = k - 1; j < i; ++j)
      dp[i][k] = Math.max(dp[i][k],
                          largestSumOfAverages(nums, j, k - 1) + (prefix[i] - prefix[j]) / (i - j));

    return dp[i][k];
  }
}
