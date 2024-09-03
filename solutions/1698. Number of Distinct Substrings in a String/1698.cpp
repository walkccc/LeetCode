class Solution {
 public:
  int countDistinct(string s) {
    const int n = s.length();
    int ans = 0;
    vector<long> pow(n + 1);     // pow[i] := kBase^i
    vector<long> hashes(n + 1);  // hashes[i] := the hash of s[0..i)

    pow[0] = 1;
    for (int i = 1; i <= n; ++i) {
      pow[i] = pow[i - 1] * kBase % kHash;
      hashes[i] = (hashes[i - 1] * kBase + val(s[i - 1])) % kHash;
    }

    for (int length = 1; length <= n; ++length) {
      unordered_set<int> seen;
      for (int i = 0; i + length <= n; ++i)
        seen.insert(getHash(i, i + length, hashes, pow));
      ans += seen.size();
    }

    return ans;
  }

 private:
  static constexpr int kBase = 26;
  static constexpr int kHash = 1'000'000'007;

  static constexpr int val(char c) {
    return c - 'a';
  }

  // Returns the hash of s[l..r).
  long getHash(int l, int r, const vector<long>& hashes,
               const vector<long>& pow) {
    const long hash = (hashes[r] - hashes[l] * pow[r - l]) % kHash;
    return hash < 0 ? hash + kHash : hash;
  }
};
