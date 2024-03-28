class Solution {
 public:
  int minNonZeroProduct(int p) {
    // Can always turn [1..2^p - 1] to [1, 1, ..., 2^p - 2, 2^p - 2, 2^p - 1].
    const long n = 1L << p;
    const long halfCount = n / 2 - 1;
    return modPow(n - 2, halfCount) * ((n - 1) % kMod) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  long modPow(long x, long n) {
    if (n == 0)
      return 1L;
    x %= kMod;
    if (n % 2 == 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x, n / 2) % kMod;
  }
};
