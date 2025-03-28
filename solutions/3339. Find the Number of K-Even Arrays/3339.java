class Solution {
  public int countOfArrays(int n, int m, int k) {
    final int MOD = 1_000_000_007;
    final int even = m / 2;   // the number of even numbers in [1, m]
    final int odd = m - even; // the number of odd numbers in [1, m]
    // dp[i][j][0/1] := the number of arrays of length i with j consecutive even
    // number pairs ending in an even number (0) or an odd number (1)
    int[][][] dp = new int[n + 1][k + 1][2];

    // Base case: arrays of length 1
    // For an array of length 1, we can't have any even number pairs yet.
    dp[1][0][0] = even;
    dp[1][0][1] = odd;

    for (int i = 2; i <= n; ++i)
      for (int j = 0; j <= k; ++j) {
        // 1. Appending an even number to an array ending in an even number
        //    creates a new consecutive even number pair.
        // 2. Appending an even number to an array ending in an odd number.
        dp[i][j][0] = (int) (((long) (j > 0 ? dp[i - 1][j - 1][0] : 0) * even +
                              (long) dp[i - 1][j][1] * even) %
                             MOD);
        // 3. Appending an odd number to an array.
        dp[i][j][1] = (int) ((long) (dp[i - 1][j][0] + dp[i - 1][j][1]) * odd % MOD);
      }

    return (dp[n][k][0] + dp[n][k][1]) % MOD;
  }
}
