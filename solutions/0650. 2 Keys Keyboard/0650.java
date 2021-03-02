class Solution {
  public int minSteps(int n) {
    // dp[i] := min steps to get i 'A'
    int[] dp = new int[n + 1];

    for (int i = 2; i <= n; ++i) {
      dp[i] = i; // copy 'A', then paste 'A' i - 1 times
      for (int j = i / 2; j > 2; --j)
        if (i % j == 0) {
          dp[i] = dp[j] + i / j; // paste dp[j] i / j times
          break;
        }
    }

    return dp[n];
  }
}
