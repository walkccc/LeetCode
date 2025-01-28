class Solution {
  public int distanceSum(int m, int n, int k) {
    final long rowContrib = 1L * n * n * (1L * m * m * m - m) / 6 % kMod;
    final long colContrib = 1L * m * m * (1L * n * n * n - n) / 6 % kMod;
    return (int) ((rowContrib + colContrib) % kMod * nCk(m * n - 2, k - 2) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  private long nCk(int n, int k) {
    long res = 1;
    for (int i = 1; i <= k; ++i)
      // By Fermat's little theorem.
      res = res * (n - i + 1) % kMod * modPow(i, kMod - 2) % kMod;
    return res;
  }

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }
}
