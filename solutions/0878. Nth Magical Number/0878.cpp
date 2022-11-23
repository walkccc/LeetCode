class Solution {
 public:
  int nthMagicalNumber(long n, long a, long b) {
    constexpr int kMod = 1'000'000'007;
    const long lcm = a * b / __gcd(a, b);
    long l = min(a, b);
    long r = min(a, b) * n;

    while (l < r) {
      const long m = (l + r) / 2;
      if (m / a + m / b - m / lcm >= n)
        r = m;
      else
        l = m + 1;
    }

    return l % kMod;
  }
};
