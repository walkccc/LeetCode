class Solution {
  public int countGoodArrays(int n, int m, int k) {
    final long[][] factAndInvFact = getFactAndInvFact(n);
    final long[] fact = factAndInvFact[0];
    final long[] invFact = factAndInvFact[1];
    return (int) (m * modPow(m - 1, n - k - 1) % kMod * nCk(n - 1, k, fact, invFact) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }

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
