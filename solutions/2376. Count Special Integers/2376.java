class Solution {
  // Same as 1012. Numbers With Repeated Digits
  public int countSpecialNumbers(int n) {
    final int digitSize = (int) Math.log10(n) + 1;
    Integer[][][] mem = new Integer[digitSize + 1][1 << 10][2];
    return count(String.valueOf(n), 0, 0, true, mem) - 1; // - 0;
  }

  // Returns the number of special integers, considering the i-th digit, where
  // `used` is the bitmask of the used digits, and `isTight` indicates if the
  // current digit is tightly bound.
  private int count(final String s, int i, int used, boolean isTight, Integer[][][] mem) {
    if (i == s.length())
      return 1;
    if (mem[i][used][isTight ? 1 : 0] != null)
      return mem[i][used][isTight ? 1 : 0];

    int res = 0;

    final int maxDigit = isTight ? s.charAt(i) - '0' : 9;
    for (int d = 0; d <= maxDigit; ++d) {
      // `d` is used.
      if ((used >> d & 1) == 1)
        continue;
      // Use `d` now.
      final boolean nextIsTight = isTight && (d == maxDigit);
      if (used == 0 && d == 0) // Don't count leading 0s as used.
        res += count(s, i + 1, used, nextIsTight, mem);
      else
        res += count(s, i + 1, used | 1 << d, nextIsTight, mem);
    }

    return mem[i][used][isTight ? 1 : 0] = res;
  }
}
