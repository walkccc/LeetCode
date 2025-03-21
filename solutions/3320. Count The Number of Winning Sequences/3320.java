class Solution {
  public int countWinningSequences(String s) {
    Long[][][] mem = new Long[s.length()][3][2 * s.length()];
    final long ans = count(s, 0, 0, 0, mem) + count(s, 0, 1, 0, mem) + count(s, 0, 2, 0, mem);
    return (int) ((ans / 2) % MOD);
  }

  private static final int MOD = 1_000_000_007;

  // Returns the number of distinct sequences Bob can use to beat Alice for
  // s[i..n), where the previous character is `prev` (0: F, 1: W, 2: E) and the
  // number of points that Bob is having is `bob`.
  private long count(final String s, int i, int prev, int bob, Long[][][] mem) {
    if (i == s.length())
      return bob > 0 ? 1 : 0;
    final int bobIdx = bob + s.length();
    if (mem[i][prev][bobIdx] != null)
      return mem[i][prev][bobIdx];

    long f = 0; // If Bob summons a Fire Dragon at i.
    long w = 0; // If Bob summons a Water Serpent at i.
    long e = 0; // If Bob summons a Earth Golem at i.

    switch (s.charAt(i)) {
      case 'F':
        if (prev != 0)
          f = count(s, i + 1, 0, bob, mem) % MOD;
        if (prev != 1)
          w = count(s, i + 1, 1, bob + 1, mem) % MOD;
        if (prev != 2)
          e = count(s, i + 1, 2, bob - 1, mem) % MOD;
        break;
      case 'W':
        if (prev != 0)
          f = count(s, i + 1, 0, bob - 1, mem) % MOD;
        if (prev != 1)
          w = count(s, i + 1, 1, bob, mem) % MOD;
        if (prev != 2)
          e = count(s, i + 1, 2, bob + 1, mem) % MOD;
        break;
      case 'E':
        if (prev != 0)
          f = count(s, i + 1, 0, bob + 1, mem) % MOD;
        if (prev != 1)
          w = count(s, i + 1, 1, bob - 1, mem) % MOD;
        if (prev != 2)
          e = count(s, i + 1, 2, bob, mem) % MOD;
        break;
      default:
        break;
    }

    return mem[i][prev][bobIdx] = f + w + e;
  }
}
