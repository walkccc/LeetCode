class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0;
    const vector<bool> isPrime = sieveEratosthenes(n);
    return ranges::count(isPrime, true);
  }

 private:
  vector<bool> sieveEratosthenes(int n) {
    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i < n; ++i)
      if (isPrime[i])
        for (int j = i * i; j < n; j += i)
          isPrime[j] = false;
    return isPrime;
  }
};
