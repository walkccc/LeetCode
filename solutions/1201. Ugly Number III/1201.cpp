class Solution {
 public:
  int nthUglyNumber(int n, long a, long b, long c) {
    const long ab = a * b / __gcd(a, b);
    const long ac = a * c / __gcd(a, c);
    const long bc = b * c / __gcd(b, c);
    const long abc = a * bc / __gcd(a, bc);
    int l = 1;
    int r = 2'000'000'000;

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (m / a + m / b + m / c - m / ab - m / ac - m / bc + m / abc >= n)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};
