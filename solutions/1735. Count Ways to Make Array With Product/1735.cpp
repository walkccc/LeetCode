class Solution {
 public:
  vector<int> waysToFillArray(vector<vector<int>>& queries) {
    constexpr int kMax = 10000;
    constexpr int kMaxFreq = 13;  // 2^13 = 8192 < kMax
    const vector<int> minPrimeFactors = sieveEratosthenes(kMax + 1);
    const auto [fact, invFact] = getFactAndInvFact(kMax + kMaxFreq - 1);
    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int n = query[0];
      const int k = query[1];
      int res = 1;
      for (const auto& [_, freq] : getPrimeFactorsCount(k, minPrimeFactors))
        res = static_cast<long>(res) * nCk(n - 1 + freq, freq, fact, invFact) %
              kMod;
      ans.push_back(res);
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  // Gets the minimum prime factor of i, where 1 < i <= n.
  vector<int> sieveEratosthenes(int n) {
    vector<int> minPrimeFactors(n + 1);
    iota(minPrimeFactors.begin() + 2, minPrimeFactors.end(), 2);
    for (int i = 2; i * i < n; ++i)
      if (minPrimeFactors[i] == i)  // `i` is prime.
        for (int j = i * i; j < n; j += i)
          minPrimeFactors[j] = min(minPrimeFactors[j], i);
    return minPrimeFactors;
  }

  unordered_map<int, int> getPrimeFactorsCount(
      int num, const vector<int>& minPrimeFactors) {
    unordered_map<int, int> count;
    while (num > 1) {
      const int divisor = minPrimeFactors[num];
      while (num % divisor == 0) {
        num /= divisor;
        ++count[divisor];
      }
    }
    return count;
  }

  pair<vector<long>, vector<long>> getFactAndInvFact(int n) {
    vector<long> fact(n + 1);
    vector<long> invFact(n + 1);
    vector<long> inv(n + 1);
    fact[0] = invFact[0] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 1; i <= n; ++i) {
      if (i >= 2)
        inv[i] = kMod - kMod / i * inv[kMod % i] % kMod;
      fact[i] = fact[i - 1] * i % kMod;
      invFact[i] = invFact[i - 1] * inv[i] % kMod;
    }
    return {fact, invFact};
  }

  int nCk(int n, int k, const vector<long>& fact, const vector<long>& invFact) {
    return fact[n] * invFact[k] % kMod * invFact[n - k] % kMod;
  }
};
