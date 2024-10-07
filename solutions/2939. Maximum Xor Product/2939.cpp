class Solution {
 public:
  int maximumXorProduct(long long a, long long b, int n) {
    constexpr int kMod = 1'000'000'007;
    if (n > 0)
      for (long bit = 1L << (n - 1); bit > 0; bit >>= 1)
        // Pick a bit if it makes min(a, b) larger.
        if ((min(a, b) & bit) == 0) {
          a ^= bit;
          b ^= bit;
        }
    return a % kMod * (b % kMod) % kMod;
  }
};
