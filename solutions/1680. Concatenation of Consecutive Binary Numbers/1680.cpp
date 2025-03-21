class Solution {
 public:
  int concatenatedBinary(int n) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;

    for (int i = 1; i <= n; ++i)
      ans = ((ans << numberOfBits(i)) % kMod + i) % kMod;

    return ans;
  }

 private:
  int numberOfBits(int n) {
    return log2(n) + 1;
  }
};
