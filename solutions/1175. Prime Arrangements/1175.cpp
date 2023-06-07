class Solution {
 public:
  int numPrimeArrangements(int n) {
    constexpr int kMod = 1'000'000'007;
    const int count = countPrimes(n);
    return (factorial(count, kMod) * factorial(n - count, kMod)) % kMod;
  }

 private:
  int countPrimes(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;

    for (int i = 0; i <= sqrt(n); ++i)
      if (prime[i])
        for (int j = i * i; j <= n; j += i)
          prime[j] = false;

    return count(begin(prime), end(prime), true);
  }

  long factorial(int n, const int kMod) {
    long fact = 1;
    for (int i = 1; i <= n; ++i)
      fact = fact * i % kMod;
    return fact;
  }
};
