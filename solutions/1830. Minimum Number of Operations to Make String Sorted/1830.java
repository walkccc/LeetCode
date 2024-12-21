class Solution {
  public int makeStringSorted(String s) {
    final int kMod = 1_000_000_007;
    final int n = s.length();
    final long[][] factAndInvFact = getFactAndInvFact(n);
    final long[] fact = factAndInvFact[0];
    final long[] invFact = factAndInvFact[1];
    int ans = 0;
    int[] count = new int[26];

    for (int i = n - 1; i >= 0; --i) {
      final int order = s.charAt(i) - 'a';
      ++count[order];
      long perm = Arrays.stream(count, 0, order).sum() * fact[n - 1 - i] % kMod;
      for (int j = 0; j < 26; ++j)
        perm = perm * invFact[count[j]] % kMod;
      ans += perm;
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
}
