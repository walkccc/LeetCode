class Solution {
 public:
  int makeStringSorted(string s) {
    const int n = s.length();
    const auto [fact, invFact] = getFactAndInvFact(n);
    int ans = 0;
    vector<int> count(26);

    for (int i = n - 1; i >= 0; --i) {
      const int order = s[i] - 'a';
      ++count[order];
      long perm = accumulate(count.begin(), count.begin() + order, 0) *
                  fact[n - 1 - i] % kMod;
      for (int j = 0; j < 26; ++j)
        perm = perm * invFact[count[j]] % kMod;
      ans = (ans + perm) % kMod;
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
};
