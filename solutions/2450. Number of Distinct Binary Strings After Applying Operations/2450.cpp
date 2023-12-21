class Solution {
 public:
  int countDistinctStrings(string s, int k) {
    // Since the content of `s` doesn't matter, for each i in [0, n - k], we can
    // flip s[i..i + k] or don't flip it. Therefore, there's 2^(n - k + 1) ways.
    return modPow(2, s.length() - k + 1);
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
