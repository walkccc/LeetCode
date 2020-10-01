class Solution {
 public:
  int nthMagicalNumber(long N, long A, long B) {
    const int kMod = int(1e9 + 7);

    long lcm = A * B / __gcd(A, B);
    long l = min(A, B);
    long r = min(A, B) * N;

    while (l < r) {
      long m = l + (r - l) / 2;
      if (m / A + m / B - m / lcm < N)
        l = m + 1;
      else
        r = m;
    }

    return l % kMod;
  }
};