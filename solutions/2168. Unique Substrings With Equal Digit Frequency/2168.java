class Solution {
  public int equalDigitFrequency(String s) {
    final int n = s.length();
    int[][] counts = new int[n][]; // counts[i] := the counter map of s[0..i]
    int[] count = new int[10];
    long[] pows = new long[n + 1]; // pows[i] := BASE^i % HASH
    // hash[i] = the hash of the first i letters of s, where hash[i] =
    // (26^(i - 1) * s[0] + 26^(i - 2) * s[1] + ... + s[i - 1]) % HASH
    long[] hash = new long[n + 1];
    Set<Integer> seen = new HashSet<>();

    pows[0] = 1;

    for (int i = 0; i < n; ++i) {
      ++count[s.charAt(i) - '0'];
      counts[i] = count.clone();
      pows[i + 1] = pows[i] * BASE % HASH;
      hash[i + 1] = (hash[i] * BASE + val(s.charAt(i))) % HASH;
    }

    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j)
        if (isSameFreq(counts, i, j))
          seen.add(getRollingHash(i, j + 1, hash, pows));

    return seen.size();
  }

  private static final int MAX = 1001;
  private static final int BASE = 11;
  private static final int HASH = 1_000_000_007;

  private static int val(char c) {
    return c - '0' + 1;
  }

  // Returns true if s[i..j] has the same digit frequency.j
  private boolean isSameFreq(int[][] counts, int i, int j) {
    int[] count = counts[j].clone();
    if (i > 0)
      for (int num = 0; num < 10; ++num)
        count[num] -= counts[i - 1][num];
    return equalFreq(count);
  }

  private boolean equalFreq(int[] count) {
    int minfreq = MAX;
    int maxfreq = 0;
    for (final int freq : count)
      if (freq > 0) {
        minfreq = Math.min(minfreq, freq);
        maxfreq = Math.max(maxfreq, freq);
      }
    return minfreq == maxfreq;
  }

  // Returns the rolling hash of s[l..r).
  private int getRollingHash(int l, int r, long[] hash, long[] pows) {
    final long h = (hash[r] - hash[l] * pows[r - l]) % HASH;
    return (int) (h < 0 ? h + HASH : h);
  }
}
