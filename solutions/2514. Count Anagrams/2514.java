class Solution {
  public int countAnagrams(String s) {
    final int n = s.length();
    final long[][] factAndInvFact = getFactAndInvFact(n);
    final long[] fact = factAndInvFact[0];
    final long[] invFact = factAndInvFact[1];
    long ans = 1;

    for (final String word : s.split(" ")) {
      ans = ans * fact[word.length()] % kMod;
      int[] count = new int[26];
      for (final char c : word.toCharArray())
        ++count[c - 'a'];
      for (final int freq : count)
        ans = ans * invFact[freq] % kMod;
    }

    return (int) ans;
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
}
