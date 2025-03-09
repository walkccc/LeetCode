class Solution {
  public int distanceSum(int m, int n, int k) {
    final long rowContrib = 1L * n * n * (1L * m * m * m - m) / 6 % MOD;
    final long colContrib = 1L * m * m * (1L * n * n * n - n) / 6 % MOD;
    return (int) ((rowContrib + colContrib) % MOD * nCk(m * n - 2, k - 2) % MOD);
  }

  private static final int MOD = 1_000_000_007;

  private long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i)
      // By Fermat's little theorem.
      res = res * (n - i + 1) % MOD * modPow(i, MOD - 2) % MOD;
    return res;
  }

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % MOD;
    return modPow(x * x % MOD, n / 2);
  }
}
