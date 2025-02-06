class Solution {
  public int stringCount(int n) {
    // There're three invalid conditions:
    //   a. count('l') == 0
    //   b. count('e') < 2
    //   c. count('t') == 0
    //
    // By Principle of Inclusion-Exclusion (PIE):
    //   ans = allCount - a - b - c + ab + ac + bc - abc
    final long allCount = modPow(26, n);
    final long a = modPow(25, n);
    final long b = modPow(25, n);
    final long c = modPow(25, n) + n * modPow(25, n - 1);
    final long ab = modPow(24, n) + n * modPow(24, n - 1);
    final long ac = modPow(24, n);
    final long bc = modPow(24, n) + n * modPow(24, n - 1);
    final long abc = modPow(23, n) + n * modPow(23, n - 1);
    return (int) (((allCount - a - b - c + ab + ac + bc - abc) % kMod + kMod) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  private long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }
}
