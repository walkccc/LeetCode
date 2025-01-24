class Solution {
 public:
  int numberOfSequence(int n, vector<int>& sick) {
    const auto [fact, invFact] = getFactAndInvFact(n - sick.size());
    long ans = fact[n - sick.size()];  // the number of infected children
    int prevSick = -1;

    for (int i = 0; i < sick.size(); ++i) {
      // The segment [prevSick + 1, sick - 1] are the current non-infected
      // children.
      const int nonInfected = sick[i] - prevSick - 1;
      prevSick = sick[i];
      if (nonInfected == 0)
        continue;
      ans *= invFact[nonInfected];
      ans %= kMod;
      if (i > 0) {
        // There're two choices per second since the children at the two
        // endpoints can both be the infect candidates. So, there are
        // 2^{nonInfected - 1} ways to infect all children in the current
        // segment.
        ans *= modPow(2, nonInfected - 1);
        ans %= kMod;
      }
    }

    const int nonInfected = n - sick.back() - 1;
    ans *= invFact[nonInfected];
    return ans % kMod;
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

  long modPow(long x, long n) {
    if (n == 0)
      return 1;
    if (n % 2 == 1)
      return x * modPow(x % kMod, (n - 1)) % kMod;
    return modPow(x * x % kMod, (n / 2)) % kMod;
  }
};
