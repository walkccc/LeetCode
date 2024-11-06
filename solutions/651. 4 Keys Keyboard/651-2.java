class Solution {
  public int maxA(int n) {
    // dp[i] := the maximum 'A' can be printed with i pressings
    int[] dp = new int[n + 1];

    for (int i = 0; i <= n; ++i) {
      dp[i] = i; // 'A' * i
      for (int j = 0; j <= i - 3; ++j)
        dp[i] = Math.max(dp[i], dp[j] * (i - j - 1));
    }

    return dp[n];
  }
}
