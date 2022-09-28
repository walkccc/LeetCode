class Solution {
  // same as 1012. Numbers With Repeated Digits
  public int countSpecialNumbers(int n) {
    final int digitSize = (int) Math.log10(n) + 1;
    // dp[i][j][k] := # of special integers that belong to the interval
    // [0, 10^i] with `usedMask` j, where k is 0/1 tight constraint
    dp = new Integer[digitSize + 1][1 << 10][2];
    return count(String.valueOf(n), digitSize, 0, true) - 1; // - 0;
  }

  private Integer[][][] dp;

  private int count(final String s, int digitSize, int usedMask, boolean isTight) {
    if (digitSize == 0)
      return 1;
    if (dp[digitSize][usedMask][isTight ? 1 : 0] != null)
      return dp[digitSize][usedMask][isTight ? 1 : 0];

    int ans = 0;
    final int maxDigit = isTight ? s.charAt(s.length() - digitSize) - '0' : 9;

    for (int digit = 0; digit <= maxDigit; ++digit) {
      // `digit` is used
      if ((usedMask >> digit & 1) == 1)
        continue;
      // use `digit` now
      final boolean nextIsTight = isTight && (digit == maxDigit);
      if (usedMask == 0 && digit == 0) // don't count leading 0s as used
        ans += count(s, digitSize - 1, usedMask, nextIsTight);
      else
        ans += count(s, digitSize - 1, usedMask | 1 << digit, nextIsTight);
    }

    return dp[digitSize][usedMask][isTight ? 1 : 0] = ans;
  }
}
