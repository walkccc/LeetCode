class Solution {
  public double largestSumOfAverages(int[] A, int K) {
    final int n = A.length;
    // dp[i][k] := largest score to partition first i nums into k groups
    dp = new double[n + 1][K + 1];
    prefix = new double[n + 1];

    for (int i = 0; i < n; ++i)
      prefix[i + 1] = A[i] + prefix[i];

    return largestSumOfAverages(A, n, K);
  }

  private double[][] dp;
  private double[] prefix;

  private double largestSumOfAverages(int[] A, int i, int k) {
    if (k == 1)
      return prefix[i] / i;
    if (dp[i][k] > 0.0)
      return dp[i][k];

    // try all possible partitions
    for (int j = k - 1; j < i; ++j)
      dp[i][k] =
          Math.max(dp[i][k], largestSumOfAverages(A, j, k - 1) + (prefix[i] - prefix[j]) / (i - j));

    return dp[i][k];
  }
}
