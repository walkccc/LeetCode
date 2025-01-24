class Solution {
 public:
  int maximumPrimeDifference(vector<int>& nums) {
    constexpr int kMax = 100;
    const vector<bool> isPrime = sieveEratosthenes(kMax + 1);
    int minPrimeIndex = -1;
    int maxPrimeIndex = -1;

    for (int i = 0; i < nums.size(); ++i)
      if (isPrime[nums[i]]) {
        if (minPrimeIndex == -1)
          minPrimeIndex = i;
        maxPrimeIndex = i;
      }

    return maxPrimeIndex - minPrimeIndex;
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
