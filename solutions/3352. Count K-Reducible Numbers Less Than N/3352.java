class Solution {
  public int countKReducibleNumbers(String s, int k) {
    Integer[][][] mem = new Integer[s.length()][s.length() + 1][2];
    return count(s, 0, 0, true, k, getOps(s), mem) - 1; // - 0
  }

  private static final int MOD = 1_000_000_007;

  // Returns the number of positive integers less than n that are k-reducible,
  // considering the i-th digit, where `setBits` is the number of set bits in
  // the current number, and `tight` indicates if the current digit is
  // tightly bound.
  private int count(String s, int i, int setBits, boolean tight, int k, int[] ops,
                    Integer[][][] mem) {
    if (i == s.length())
      return (ops[setBits] < k && !tight) ? 1 : 0;
    if (mem[i][setBits][tight ? 1 : 0] != null)
      return mem[i][setBits][tight ? 1 : 0];

    int res = 0;
    final int maxDigit = tight ? s.charAt(i) - '0' : 1;

    for (int d = 0; d <= maxDigit; ++d) {
      final boolean nextTight = tight && (d == maxDigit);
      res += count(s, i + 1, setBits + d, nextTight, k, ops, mem);
      res %= MOD;
    }

    return mem[i][setBits][tight ? 1 : 0] = res;
  }

  // Returns the number of operations to reduce a number to 0.
  private int[] getOps(String s) {
    int[] ops = new int[s.length() + 1];
    for (int num = 2; num <= s.length(); ++num)
      ops[num] = 1 + ops[Integer.bitCount(num)];
    return ops;
  }
}
