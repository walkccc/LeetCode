class Solution {
  public int numWays(int steps, int arrLen) {
    final long kMod = (long) 1e9 + 7;
    final int n = Math.min(arrLen, steps / 2 + 1);

    long[] dp = new long[n]; // dp[i] := # of ways to stay on index i
    dp[0] = 1;

    while (steps-- > 0) {
      long[] newDp = new long[n];
      for (int i = 0; i < n; ++i) {
        newDp[i] = dp[i];
        if (i - 1 >= 0)
          newDp[i] += dp[i - 1];
        if (i + 1 < n)
          newDp[i] += dp[i + 1];
        newDp[i] %= kMod;
      }
      dp = newDp;
    }

    return (int) dp[0];
  }
}
