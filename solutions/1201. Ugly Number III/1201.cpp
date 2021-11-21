class Solution {
 public:
  int nthUglyNumber(int n, long a, long b, long c) {
    long ab = a * b / __gcd(a, b);
    long ac = a * c / __gcd(a, c);
    long bc = b * c / __gcd(b, c);
    long abc = a * bc / __gcd(a, bc);
    int l = 1;
    int r = (int)2 * 1e9;

    while (l < r) {
      int m = l + (r - l) / 2;
      if (m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc >= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
