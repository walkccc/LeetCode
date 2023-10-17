class Solution {
 public:
  int countGoodSubsequences(string s) {
    // For each frequency f in [1, max(freq)], start with "" and calculate how
    // many subseqs can be constructed with each letter's frequency = f.
    //
    // E.g., s = "abb", so f = max(freq) = 2.
    //
    // For f = 1, with 1 way to build "", choose any 'a' to construct a good
    // subseq, so # of good subseqs = 1 + 1 * (1, 1) = 2 ("", "a"). Next, add
    // 'b' and # of good subseqs = 2 + 2 * (2, 1) = 6 ("", "a", "b1", "b2",
    // "ab1", "ab2"). So, the # of good subseqs for f = 1 is 5 since we need to
    // exclude "".
    //
    // For f = 2, with 1 way to build "", choose any two 'b's to construct a
    // good subseq, so # of good subseqs = 1 + 1 * (2, 2) is 2 ("", "bb"). So,
    // the # of good subseqs for f = 2 = 1 since we need to exclude "".
    //
    // Therefore, the # of good subseqs for "aab" = 5 + 1 = 6.
    constexpr int kMod = 1'000'000'007;
    int ans = 0;
    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    const int maxFreq = ranges::max(count);
    const auto [fact, invFact] = getFactAndInvFact(maxFreq, kMod);

    for (int freq = 1; freq <= maxFreq; ++freq) {
      long numSubseqs = 1;  // ""
      for (const int charFreq : count)
        if (charFreq >= freq)
          numSubseqs = (numSubseqs +
                        numSubseqs * nCk(charFreq, freq, fact, invFact, kMod)) %
                       kMod;
      ans += numSubseqs - 1;  // Minus "".
      ans %= kMod;
    }

    return ans;
  }

 private:
  pair<vector<long>, vector<long>> getFactAndInvFact(int n, int kMod) {
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

  int nCk(int n, int k, const vector<long>& fact, const vector<long>& invFact,
          int kMod) {
    return fact[n] * invFact[k] % kMod * invFact[n - k] % kMod;
  }
};
