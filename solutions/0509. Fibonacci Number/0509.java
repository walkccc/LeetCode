class Solution {
  public int fib(int n) {
    if (n < 2)
      return n;

    int[] dp = {0, 0, 1};

    for (int i = 2; i <= n; ++i) {
      dp[0] = dp[1];
      dp[1] = dp[2];
      dp[2] = dp[0] + dp[1];
    }

    return dp[2];
  }
}
