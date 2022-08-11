class Solution {
  public int nthMagicalNumber(long n, long a, long b) {
    final int kMod = (int) 1e9 + 7;
    final long lcm = a * b / gcd(a, b);
    long l = Math.min(a, b);
    long r = Math.min(a, b) * n;

    while (l < r) {
      final long m = (l + r) / 2;
      if (m / a + m / b - m / lcm >= n)
        r = m;
      else
        l = m + 1;
    }

    return (int) (l % kMod);
  }

  private long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
