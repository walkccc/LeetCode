class Solution {
 public:
  vector<int> closestPrimes(int left, int right) {
    const vector<bool> isPrime = sieveEratosthenes(right + 1);
    vector<int> primes;

    for (int i = left; i <= right; ++i)
      if (isPrime[i])
        primes.push_back(i);

    if (primes.size() < 2)
      return {-1, -1};

    int minDiff = INT_MAX;
    int num1 = -1;
    int num2 = -1;

    for (int i = 1; i < primes.size(); ++i) {
      const int diff = primes[i] - primes[i - 1];
      if (diff < minDiff) {
        minDiff = diff;
        num1 = primes[i - 1];
        num2 = primes[i];
      }
    }

    return {num1, num2};
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
