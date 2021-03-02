class Solution {
  public int maxA(int N) {
    // dp[i] := max 'A' can be printed w/ i pressings
    int[] dp = new int[N + 1];

    for (int i = 0; i <= N; ++i) {
      dp[i] = i; // 'A' * i
      for (int j = 0; j <= i - 3; ++j)
        dp[i] = Math.max(dp[i], dp[j] * (i - j - 1));
    }

    return dp[N];
  }
}
