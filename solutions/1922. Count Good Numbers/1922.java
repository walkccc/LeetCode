class Solution {
  public int countGoodNumbers(long n) {
    return (int) (myPow(4 * 5, n / 2) * (n % 2 == 1 ? 5 : 1) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  private long myPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * myPow(x, n - 1) % kMod;
    return myPow(x * x % kMod, n / 2);
  }
}
