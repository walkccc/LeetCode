class Solution {
  public int countOfArrays(int n, int m, int k) {
    final int MOD = 1_000_000_007;
    final int even = m / 2;   // the number of even numbers in [1, m]
    final int odd = m - even; // the number of odd numbers in [1, m]
    // dp[j][0/1] := the number of arrays of length so far i with j consecutive
    // even number pairs ending in an even number (0) or an odd number (1)
    int[][] dp = new int[k + 1][2];

    // Base case: arrays of length 1
    // For an array of length 1, we can't have any even number pairs yet.
    dp[0][0] = even;
    dp[0][1] = odd;

    for (int i = 2; i <= n; ++i) {
      int[][] newDp = new int[k + 1][2];
      for (int j = 0; j <= k; ++j) {
        // 1. Appending an even number to an array ending in an even number
        //    creates a new consecutive even number pair.
        // 2. Appending an even number to an array ending in an odd number.
        newDp[j][0] =
            (int) (((long) (j > 0 ? dp[j - 1][0] : 0) * even + (long) dp[j][1] * even) % MOD);
        // 3. Appending an odd number to an array.
        newDp[j][1] = (int) ((long) (dp[j][0] + dp[j][1]) * odd % MOD);
      }
      dp = newDp;
    }

    return (dp[k][0] + dp[k][1]) % MOD;
  }
}
