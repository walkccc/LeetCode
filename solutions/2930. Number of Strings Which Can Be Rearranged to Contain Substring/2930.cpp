class Solution {
 public:
  int stringCount(int n) {
    // There're three invalid conditions:
    //   a. count('l') == 0
    //   b. count('e') < 2
    //   c. count('t') == 0
    //
    // By Principle of Inclusion-Exclusion (PIE):
    //   ans = allCount - a - b - c + ab + ac + bc - abc
    const long allCount = modPow(26, n);
    const long a = modPow(25, n);
    const long b = modPow(25, n);
    const long c = modPow(25, n) + n * modPow(25, n - 1);
    const long ab = modPow(24, n) + n * modPow(24, n - 1);
    const long ac = modPow(24, n);
    const long bc = modPow(24, n) + n * modPow(24, n - 1);
    const long abc = modPow(23, n) + n * modPow(23, n - 1);
    return ((allCount - a - b - c + ab + ac + bc - abc) % kMod + kMod) % kMod;
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
