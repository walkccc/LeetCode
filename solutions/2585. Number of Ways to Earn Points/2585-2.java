class Solution {
  public int waysToReachTarget(int target, int[][] types) {
    final int kMod = 1_000_000_007;
    // dp[j] := the number of ways to earn j points with the types so far
    int[] dp = new int[target + 1];
    dp[0] = 1;

    for (int[] type : types) {
      final int count = type[0];
      final int mark = type[1];
      for (int j = target; j >= 0; --j)
        for (int solved = 1; solved <= count; ++solved)
          if (j - solved * mark >= 0) {
            dp[j] += dp[j - solved * mark];
            dp[j] %= kMod;
          }
    }

    return dp[target];
  }
}
