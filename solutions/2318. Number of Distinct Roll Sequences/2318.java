class Solution {
  public int distinctSequences(int n) {
    int[][][] mem = new int[n + 1][7][7];
    return distinctSequences(n, 0, 0);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the number of distinct sequences for n dices with `prev` and
  // `prevPrev`.
  private int distinctSequences(int n, int prev, int prevPrev, int[][][] mem) {
    if (n == 0)
      return 1;
    if (mem[n][prev][prevPrev] > 0)
      return mem[n][prev][prevPrev];

    for (int dice = 1; dice <= 6; ++dice)
      if (dice != prev && dice != prevPrev && (prev == 0 || gcd(dice, prev) == 1)) {
        mem[n][prev][prevPrev] += distinctSequences(n - 1, dice, prev, mem);
        mem[n][prev][prevPrev] %= kMod;
      }

    return mem[n][prev][prevPrev];
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
