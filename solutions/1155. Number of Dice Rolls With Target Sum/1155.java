class Solution {
  public int numRollsToTarget(int d, int f, int target) {
    final int kMod = (int) 1e9 + 7;
    int[] dp = new int[target + 1];
    dp[0] = 1;

    while (d-- > 0) {
      int[] newDp = new int[target + 1];
      for (int i = 1; i <= f; ++i)
        for (int t = i; t <= target; ++t)
          newDp[t] = (newDp[t] + dp[t - i]) % kMod;
      dp = newDp;
    }

    return dp[target];
  }
}
