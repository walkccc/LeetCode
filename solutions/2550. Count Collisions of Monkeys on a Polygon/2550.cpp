class Solution {
 public:
  int monkeyMove(int n) {
    const int res = modPow(2, n) - 2;
    return res < 0 ? res + kMod : res;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  int modPow(long x, int n) {
    if (n == 0)
      return 1;
    if (n & 1)
      return x * modPow(x, n - 1) % kMod;
    return modPow(x * x % kMod, n / 2);
  }
};
