class Solution {
 public:
  vector<vector<int>> findPrimePairs(int n) {
    const vector<bool> isPrime = sieveEratosthenes(n + 1);
    vector<vector<int>> ans;

    for (int i = 2; i <= n / 2; ++i)
      if (isPrime[i] && isPrime[n - i])
        ans.push_back({i, n - i});

    return ans;
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
