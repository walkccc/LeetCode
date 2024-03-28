class Solution {
 public:
  int concatenatedBinary(int n) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    int numberOfBits = 0;

    for (int i = 1; i <= n; ++i) {
      if (__builtin_popcount(i) == 1)
        ++numberOfBits;
      ans = ((ans << numberOfBits) % kMod + i) % kMod;
    }

    return ans;
  }
};
