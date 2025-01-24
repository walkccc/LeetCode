class Solution {
 public:
  int numberOfWays(int n, int x, int y) {
    const int maxStages = min(n, x);
    const auto [fact, invFact] = getFactAndInvFact(max(n, x));
    const vector<vector<int>> stirling = getStirling(n, maxStages);
    int ans = 0;

    for (int k = 1; k <= maxStages; ++k) {
      // 1. Choose `k` stages from `x` stages.
      long events = nCk(x, k, fact, invFact);
      // 2. Partition `n` performers into `k` stages.
      events = events * stirling[n][k] % kMod;
      // 3. Permute `k` stages.
      events = events * fact[k] % kMod;
      // 4. Score `k` stages with score in the range [1, y], so y^k ways.
      events = events * modPow(y, k) % kMod;
      ans = (ans + events) % kMod;
    }

    return ans;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

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

  // Returns a 2D array stirling, where stirling[i][j] := the number of ways to
  // partition a set of i objects into j non-empty subsets.
  //
  // https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind
  vector<vector<int>> getStirling(int n, int k) {
    vector<vector<int>> stirling(n + 1, vector<int>(k + 1));
    stirling[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      stirling[i][1] = 1;
      for (int j = 2; j <= min(i, k); ++j)
        stirling[i][j] = (static_cast<long>(j) * stirling[i - 1][j] +
                          stirling[i - 1][j - 1]) %
                         kMod;
    }
    return stirling;
  }

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
