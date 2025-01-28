class Solution {
 public:
  string longestPrefix(string s) {
    constexpr int kBase = 26;
    constexpr long kHash = 8'417'508'174'513;

    const int n = s.length();
    int maxLength = 0;
    long pow = 1;
    long prefixHash = 0;  // the hash of s[0..i]
    long suffixHash = 0;  // the hash of s[j..n)

    for (int i = 0, j = n - 1; i < n - 1; ++i, --j) {
      prefixHash = (prefixHash * kBase + val(s[i])) % kHash;
      suffixHash = (val(s[j]) * pow + suffixHash) % kHash;
      pow = pow * kBase % kHash;
      if (prefixHash == suffixHash)
        maxLength = i + 1;
    }

    return s.substr(0, maxLength);
  }

 private:
  constexpr int val(char c) {
    return c - 'a';
  }
};
