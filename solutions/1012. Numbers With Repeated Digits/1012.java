class Solution {
  public int numDupDigitsAtMostN(int n) {
    return n - countSpecialNumbers(n);
  }

  // Same as 2376. Count Special Integers
  public int countSpecialNumbers(int n) {
    final int digitSize = (int) Math.log10(n) + 1;
    // dp[i][j][k] := the number of special integers with current d i and `usedMask`
    // j, where k is 0/1 tight constraint
    dp = new Integer[digitSize + 1][1 << 10][2];
    return count(String.valueOf(n), 0, 0, true) - 1; // - 0;
  }

  private Integer[][][] dp;

  private int count(final String s, int i, int usedMask, boolean isTight) {
    if (i == s.length())
      return 1;
    if (dp[i][usedMask][isTight ? 1 : 0] != null)
      return dp[i][usedMask][isTight ? 1 : 0];

    int res = 0;

    final int maxDigit = isTight ? s.charAt(i) - '0' : 9;
    for (int d = 0; d <= maxDigit; ++d) {
      // `d` is used.
      if ((usedMask >> d & 1) == 1)
        continue;
      // Use `d` now.
      final boolean nextIsTight = isTight && (d == maxDigit);
      if (usedMask == 0 && d == 0) // Don't count leading 0s as used.
        res += count(s, i + 1, usedMask, nextIsTight);
      else
        res += count(s, i + 1, usedMask | 1 << d, nextIsTight);
    }

    return dp[i][usedMask][isTight ? 1 : 0] = res;
  }
}
