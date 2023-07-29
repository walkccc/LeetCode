class Solution {
  public int minNonZeroProduct(int p) {
    // Can always turn [1..2^p - 1] to [1, 1, ..., 2^p - 2, 2^p - 2, 2^p - 1].
    final long n = 1L << p;
    final long halfCount = n / 2 - 1;
    return (int) (myPow(n - 2, halfCount) * ((n - 1) % kMod) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  private long myPow(long x, long n) {
    if (n == 0)
      return 1L;
    x %= kMod;
    if (n % 2 == 1)
      return x * myPow(x, n - 1) % kMod;
    return myPow(x * x, n / 2) % kMod;
  }
}
