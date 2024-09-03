class Solution {
 public:
  int numPrimeArrangements(int n) {
    const int count = countPrimes(n);
    return factorial(count) * factorial(n - count) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  int countPrimes(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 0; i <= sqrt(n); ++i)
      if (prime[i])
        for (int j = i * i; j <= n; j += i)
          prime[j] = false;
    return ranges::count(prime, true);
  }

  long factorial(int n) {
    long fact = 1;
    for (int i = 2; i <= n; ++i)
      fact = fact * i % kMod;
    return fact;
  }
};
