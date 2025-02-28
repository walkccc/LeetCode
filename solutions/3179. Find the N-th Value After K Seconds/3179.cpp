class Solution {
 public:
  int valueAfterKSeconds(int n, int k) {
    const auto [fact, invFact] = getFactAndInvFact(n + k - 1);
    return nCk(n + k - 1, n - 1, fact, invFact);
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
};
