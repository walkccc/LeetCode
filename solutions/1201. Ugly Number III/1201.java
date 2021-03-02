class Solution {
  public int nthUglyNumber(int n, long a, long b, long c) {
    long ab = a * b / gcd(a, b);
    long ac = a * c / gcd(a, c);
    long bc = b * c / gcd(b, c);
    long abc = a * bc / gcd(a, bc);
    int l = 1;
    int r = 2 * (int) 1e9;

    while (l < r) {
      int m = l + (r - l) / 2;
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
