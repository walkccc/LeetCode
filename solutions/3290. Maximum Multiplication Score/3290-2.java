class Solution {
  public long maxScore(int[] a, int[] b) {
    // dp[i] := the maximum score of a[0..i]
    long[] dp = new long[4];
    Arrays.fill(dp, Long.MIN_VALUE / 2);

    for (final long num : b)
      for (int i = 3; i >= 0; --i)
        // Skip `num` or pair a[i] with `num`.
        dp[i] = Math.max(dp[i], (i > 0 ? dp[i - 1] : 0) + a[i] * num);

    return dp[3];
  }
}
