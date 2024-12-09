class Solution {
  public double probabilityOfHeads(double[] prob, int target) {
    // dp[i][j] := the probability of tossing the first i coins with j heads
    double[][] dp = new double[prob.length + 1][target + 1];
    dp[0][0] = 1.0;

    for (int i = 1; i <= prob.length; ++i)
      for (int j = 0; j <= target; ++j)
        dp[i][j] = (j > 0 ? dp[i - 1][j - 1] * prob[i - 1] : 0) + dp[i - 1][j] * (1 - prob[i - 1]);

    return dp[prob.length][target];
  }
}
