class Solution {
  public int nthUglyNumber(int n, long a, long b, long c) {
    final long ab = a * b / gcd(a, b);
    final long ac = a * c / gcd(a, c);
    final long bc = b * c / gcd(b, c);
    final long abc = a * bc / gcd(a, bc);
    int l = 1;
    int r = 2_000_000_000;

    while (l < r) {
      final int m = (l + r) / 2;
      if (m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc >= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

  private long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
