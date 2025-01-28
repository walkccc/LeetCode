class Solution {
  public int countKReducibleNumbers(String s, int k) {
    Integer[][][] mem = new Integer[s.length()][s.length() + 1][2];
    return count(s, 0, 0, true, k, getOps(s), mem) - 1; // - 0
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of positive integers less than n that are k-reducible,
  // considering the i-th digit, where `setBits` is the number of set bits in
  // the current number, and `isTight` indicates if the current digit is
  // tightly bound.
  private int count(String s, int i, int setBits, boolean isTight, int k, int[] ops,
                    Integer[][][] mem) {
    if (i == s.length())
      return (ops[setBits] < k && !isTight) ? 1 : 0;
    if (mem[i][setBits][isTight ? 1 : 0] != null)
      return mem[i][setBits][isTight ? 1 : 0];

    int res = 0;
    final int maxDigit = isTight ? s.charAt(i) - '0' : 1;

    for (int d = 0; d <= maxDigit; ++d) {
      final boolean nextIsTight = isTight && (d == maxDigit);
      res += count(s, i + 1, setBits + d, nextIsTight, k, ops, mem);
      res %= kMod;
    }

    return mem[i][setBits][isTight ? 1 : 0] = res;
  }

  // Returns the number of operations to reduce a number to 0.
  private int[] getOps(String s) {
    int[] ops = new int[s.length() + 1];
    for (int num = 2; num <= s.length(); ++num)
      ops[num] = 1 + ops[Integer.bitCount(num)];
    return ops;
  }
}
