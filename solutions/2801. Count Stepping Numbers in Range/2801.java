class Solution {
  public int countSteppingNumbers(String low, String high) {
    final String lowWithLeadingZeros =
        String.valueOf('0').repeat(high.length() - low.length()) + low;
    Integer[][][][] mem = new Integer[high.length()][11][2][2];
    return count(lowWithLeadingZeros, high, 0, 10, /*isLeadingZero=*/true, true, true, mem);
  }

  private static final int MOD = 1_000_000_007;

  // Returns the number of valid integers, considering the i-th digit, where
  // `prevDigit` is the previous digit, `tight1` indicates if the current
  // digit is tightly bound for `low`, and `tight2` indicates if the current
  // digit is tightly bound for `high`.
  private int count(final String low, final String high, int i, int prevDigit,
                    boolean isLeadingZero, boolean tight1, boolean tight2, Integer[][][][] mem) {
    if (i == high.length())
      return 1;
    if (mem[i][prevDigit][tight1 ? 1 : 0][tight2 ? 1 : 0] != null)
      return mem[i][prevDigit][tight1 ? 1 : 0][tight2 ? 1 : 0];

    int res = 0;
    final int minDigit = tight1 ? low.charAt(i) - '0' : 0;
    final int maxDigit = tight2 ? high.charAt(i) - '0' : 9;

    for (int d = minDigit; d <= maxDigit; ++d) {
      final boolean nextTight1 = tight1 && (d == minDigit);
      final boolean nextTight2 = tight2 && (d == maxDigit);
      if (isLeadingZero)
        // Can place any digit in [minDigit, maxDigit].
        res += count(low, high, i + 1, d, isLeadingZero && d == 0, nextTight1, nextTight2, mem);
      else if (Math.abs(d - prevDigit) == 1)
        // Can only place prevDigit - 1 or prevDigit + 1.
        res += count(low, high, i + 1, d, false, nextTight1, nextTight2, mem);
      res %= MOD;
    }

    return mem[i][prevDigit][tight1 ? 1 : 0][tight2 ? 1 : 0] = res;
  }
}
