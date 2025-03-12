class Solution {
  public int maxNiceDivisors(int primeFactors) {
    if (primeFactors <= 3)
      return primeFactors;
    if (primeFactors % 3 == 0)
      return (int) (modPow(3, primeFactors / 3) % MOD);
    if (primeFactors % 3 == 1)
      return (int) (4 * modPow(3, (primeFactors - 4) / 3) % MOD);
    return (int) (2 * modPow(3, (primeFactors - 2) / 3) % MOD);
  }

  private static final int MOD = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % MOD;
    return modPow(x * x % MOD, n / 2);
  }
}
