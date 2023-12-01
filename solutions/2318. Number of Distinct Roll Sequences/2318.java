class Solution {
  public int distinctSequences(int n) {
    // dp[n][prev][prevPrev] := the number of distinct sequences for n dices with
    // `prev` and `prevPrev`
    dp = new int[n + 1][7][7];
    return distinctSequences(n, 0, 0);
  }

  private static final int kMod = 1_000_000_007;
  private int[][][] dp;

  private int distinctSequences(int n, int prev, int prevPrev) {
    if (n == 0)
      return 1;
    if (dp[n][prev][prevPrev] > 0)
      return dp[n][prev][prevPrev];

    for (int dice = 1; dice <= 6; ++dice)
      if (dice != prev && dice != prevPrev && (prev == 0 || gcd(dice, prev) == 1)) {
        dp[n][prev][prevPrev] += distinctSequences(n - 1, dice, prev);
        dp[n][prev][prevPrev] %= kMod;
      }

    return dp[n][prev][prevPrev];
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
