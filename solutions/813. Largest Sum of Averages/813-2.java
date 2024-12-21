class Solution {
  public double largestSumOfAverages(int[] nums, int K) {
    final int n = nums.length;
    // dp[i][k] := the maximum score to partition the first i nums into k groups
    double[][] dp = new double[n + 1][K + 1];
    double[] prefix = new double[n + 1];

    for (int i = 1; i <= n; ++i) {
      prefix[i] = nums[i - 1] + prefix[i - 1];
      dp[i][1] = prefix[i] / i;
    }

    for (int k = 2; k <= K; ++k)
      for (int i = k; i <= n; ++i)
        for (int j = k - 1; j < i; ++j) {
          final double average = (prefix[i] - prefix[j]) / (i - j);
          dp[i][k] = Math.max(dp[i][k], dp[j][k - 1] + average);
        }

    return dp[n][K];
  }
}
