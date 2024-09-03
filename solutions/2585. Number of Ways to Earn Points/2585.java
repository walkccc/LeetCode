class Solution {
  public int waysToReachTarget(int target, int[][] types) {
    final int kMod = 1_000_000_007;
    // dp[i][j] := the number of ways to earn j points with the first i types
    int[][] dp = new int[types.length + 1][target + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= types.length; ++i) {
      final int count = types[i - 1][0];
      final int mark = types[i - 1][1];
      for (int j = 0; j <= target; ++j)
        for (int solved = 0; solved <= count; ++solved)
          if (j - solved * mark >= 0) {
            dp[i][j] += dp[i - 1][j - solved * mark];
            dp[i][j] %= kMod;
          }
    }

    return dp[types.length][target];
  }
}
