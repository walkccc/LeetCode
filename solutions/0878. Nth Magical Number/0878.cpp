class Solution {
 public:
  int nthMagicalNumber(long N, long A, long B) {
    constexpr int kMod = 1e9 + 7;
    const long lcm = A * B / __gcd(A, B);
    long l = min(A, B);
    long r = min(A, B) * N;

    while (l < r) {
      const long m = l + (r - l) / 2;
      if (m / A + m / B - m / lcm >= N)
        r = m;
      else
        l = m + 1;
    }

    return l % kMod;
  }
};
