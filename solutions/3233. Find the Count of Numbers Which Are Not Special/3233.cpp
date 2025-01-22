class Solution {
 public:
  int nonSpecialCount(int l, int r) {
    const int maxRoot = sqrt(r);
    const vector<bool> isPrime = sieveEratosthenes(maxRoot + 1);
    int specialCount = 0;

    for (int num = 2; num <= sqrt(r); ++num)
      if (isPrime[num] && l <= num * num && num * num <= r)
        ++specialCount;

    return r - l + 1 - specialCount;
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
