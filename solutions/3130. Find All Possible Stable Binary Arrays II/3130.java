class Solution {
  // Same as 3129. Find All Possible Stable Binary Arrays I
  public int numberOfStableArrays(int zero, int one, int limit) {
    final int kMod = 1_000_000_007;
    // dp[i][j][k] := the number of stable arrays, where the number of
    // occurrences of 0 is i and the number of occurrences of 1 is j and the last
    // number is k (0/1)
    long[][][] dp = new long[zero + 1][one + 1][2];

    for (int i = 0; i <= Math.min(zero, limit); ++i)
      dp[i][0][0] = 1;

    for (int j = 0; j <= Math.min(one, limit); ++j)
      dp[0][j][1] = 1;

    for (int i = 1; i <= zero; ++i)
      for (int j = 1; j <= one; ++j) {
        dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1] -
                       (i - limit < 1 ? 0 : dp[i - limit - 1][j][1]) + kMod) %
                      kMod;
        dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1] -
                       (j - limit < 1 ? 0 : dp[i][j - limit - 1][0]) + kMod) %
                      kMod;
      }

    return (int) ((dp[zero][one][0] + dp[zero][one][1]) % kMod);
  }
}
