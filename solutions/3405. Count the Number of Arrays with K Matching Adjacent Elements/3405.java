class Solution {
  public int countGoodArrays(int n, int m, int k) {
    final long[][] factAndInvFact = getFactAndInvFact(n);
    final long[] fact = factAndInvFact[0];
    final long[] invFact = factAndInvFact[1];
    return (int) (m * modPow(m - 1, n - k - 1) % MOD * nCk(n - 1, k, fact, invFact) % MOD);
  }

  private static final int MOD = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % MOD;
    return modPow(x * x % MOD, n / 2);
  }

  private long[][] getFactAndInvFact(int n) {
    long[] fact = new long[n + 1];
    long[] invFact = new long[n + 1];
    long[] inv = new long[n + 1];
    fact[0] = invFact[0] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i >= 2)
        inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
      fact[i] = fact[i - 1] * i % MOD;
      invFact[i] = invFact[i - 1] * inv[i] % MOD;
    }
    return new long[][] {fact, invFact};
  }

  private int nCk(int n, int k, long[] fact, long[] invFact) {
    return (int) (fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
  }
}
