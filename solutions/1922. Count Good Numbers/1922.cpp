class Solution {
 public:
  int countGoodNumbers(long long n) {
    return myPow(4 * 5, n / 2) * (n & 1 ? 5 : 1) % kMod;
  }

 private:
  constexpr static int kMod = 1'000'000'007;

  long myPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n & 1)
      return x * myPow(x, n - 1) % kMod;
    return myPow(x * x % kMod, n / 2);
  }
};
