class Solution {
  public int countDistinct(String s) {
    final int n = s.length();
    int ans = 0;
    long[] pow = new long[n + 1];    // pow[i] := BASE^i
    long[] hashes = new long[n + 1]; // hashes[i] := the hash of s[0..i)

    pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
      pow[i] = pow[i - 1] * BASE % HASH;
      hashes[i] = (hashes[i - 1] * BASE + val(s.charAt(i - 1))) % HASH;
    }

    for (int length = 1; length <= n; ++length) {
      Set<Long> seen = new HashSet<>();
      for (int i = 0; i + length <= n; ++i)
        seen.add(getHash(i, i + length, hashes, pow));
      ans += seen.size();
    }

    return ans;
  }

  private static final int BASE = 26;
  private static final int HASH = 1_000_000_007;

  private static int val(char c) {
    return c - 'a';
  }

  // Returns the hash of s[l..r).
  private long getHash(int l, int r, long[] hashes, long[] pow) {
    final long hash = (hashes[r] - hashes[l] * pow[r - l]) % HASH;
    return hash < 0 ? hash + HASH : hash;
  }
}
