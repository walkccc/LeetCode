class Solution {
  public int countGoodSubsequences(String s) {
    // For each frequency f in [1, max(freq)], start with "" and calculate how
    // many subsequences can be finalructed with each letter's frequency = f.
    //
    // e.g. s = "abb", so f = max(freq) = 2.
    //
    // For f = 1, with 1 way to build "", choose any 'a' to finalruct a good
    // subseq, so # of good subsequences = 1 + 1 * (1, 1) = 2 ("", "a"). Next, add
    // 'b' and # of good subsequences = 2 + 2 * (2, 1) = 6 ("", "a", "b1", "b2",
    // "ab1", "ab2"). So, the number of good subsequences for f = 1 is 5 since we need to
    // exclude "".
    //
    // For f = 2, with 1 way to build "", choose any two 'b's to finalruct a
    // good subseq, so # of good subsequences = 1 + 1 * (2, 2) is 2 ("", "bb"). So,
    // the number of good subsequences for f = 2 = 1 since we need to exclude "".
    //
    // Therefore, the number of good subsequences for "aab" = 5 + 1 = 6.
    final int kMod = 1_000_000_007;
    int ans = 0;
    int[] count = new int[26];

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    final int maxFreq = Arrays.stream(count).max().getAsInt();
    final long[][] factAndInvFact = getFactAndInvFact(maxFreq);
    final long[] fact = factAndInvFact[0];
    final long[] invFact = factAndInvFact[1];

    for (int freq = 1; freq <= maxFreq; ++freq) {
      long numSubseqs = 1; // ""
      for (final int charFreq : count)
        if (charFreq >= freq)
          numSubseqs = (numSubseqs + //
                        numSubseqs * nCk(charFreq, freq, fact, invFact)) %
                       kMod;
      ans += numSubseqs - 1; // Minus "".
      ans %= kMod;
    }

    return ans;
  }

  private static final int kMod = 1_000_000_007;

  private long[][] getFactAndInvFact(int n) {
    long[] fact = new long[n + 1];
    long[] invFact = new long[n + 1];
    long[] inv = new long[n + 1];
    fact[0] = invFact[0] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i >= 2)
        inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
      fact[i] = fact[i - 1] * i % kMod;
      invFact[i] = invFact[i - 1] * inv[i] % kMod;
    }
    return new long[][] {fact, invFact};
  }

  private int nCk(int n, int k, long[] fact, long[] invFact) {
    return (int) (fact[n] * invFact[k] % kMod * invFact[n - k] % kMod);
  }
}
