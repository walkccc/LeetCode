class Solution {
 public:
  long long sumOfLargestPrimes(string s) {
    const int n = s.length();
    unordered_set<long> primes;

    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j <= n; ++j) {
        const long num = stol(s.substr(i, j - i));
        if (!primes.contains(num) && isPrime(num))
          primes.insert(num);
      }

    vector<long> sortedPrimes{primes.begin(), primes.end()};
    ranges::sort(sortedPrimes, greater<>());
    return accumulate(
        sortedPrimes.begin(),
        sortedPrimes.begin() + min(3, static_cast<int>(sortedPrimes.size())),
        0L);
  }

 private:
  bool isPrime(long num) {
    if (num <= 1)
      return false;
    for (int i = 2; i <= sqrt(num); ++i)
      if (num % i == 0)
        return false;
    return true;
  }
};
