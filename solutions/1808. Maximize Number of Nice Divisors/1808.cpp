class Solution {
 public:
  int maxNiceDivisors(int primeFactors) {
    if (primeFactors <= 3)
      return primeFactors;
    if (primeFactors % 3 == 0)
      return modPow(3, primeFactors / 3) % kMod;
    if (primeFactors % 3 == 1)
      return 4L * modPow(3, (primeFactors - 4) / 3) % kMod;
    return 2L * modPow(3, (primeFactors - 2) / 3) % kMod;
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
