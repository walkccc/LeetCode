class Solution {
 public:
  long long maxProduct(string s) {
    const int n = s.length();
    long ans = 1;
    vector<long> pows{1};  // pows[i] := kBase^i % kHash
    // hashL[i] = the hash of the first i letters of s, where hashL[i] =
    // (26^(i - 1) * s[0] + 26^(i - 2) * s[1] + ... + s[i - 1]) % kHash
    vector<long> hashL{0};
    // hashR[i] = the hash of the last i letters of s, where hashR[i] =
    // (26^(i - 1) * s[-1] + 26^(i - 2) * s[-2] + ... + s[-i]) % kHash
    vector<long> hashR{0};
    // maxLeft[i] := the maximum odd length of palindromes in s[0..i]
    vector<int> maxLeft(n);
    // maxRight[i] := the maximum odd length of palindromes in s[i..n - 1]
    vector<int> maxRight(n);

    for (int i = 0; i < n; ++i)
      pows.push_back(pows.back() * kBase % kHash);

    for (int i = 0; i < n; ++i)
      hashL.push_back((hashL.back() * kBase + val(s[i])) % kHash);

    for (int i = n - 1; i >= 0; --i)
      hashR.push_back((hashR.back() * kBase + val(s[i])) % kHash);

    ranges::reverse(hashR);

    int maxLength = 1;
    for (int r = 0; r < n; ++r) {
      const int l = (r - maxLength - 2) + 1;
      if (l >= 0 && isPalindrome(l, r + 1, hashL, hashR, pows))
        maxLength += 2;
      maxLeft[r] = maxLength;
    }

    maxLength = 1;
    for (int l = n - 1; l >= 0; --l) {
      const int r = (l + maxLength + 2) - 1;
      if (r < n && isPalindrome(l, r + 1, hashL, hashR, pows))
        maxLength += 2;
      maxRight[l] = maxLength;
    }

    for (int i = 1; i < n; ++i)
      ans = max(ans, static_cast<long>(maxLeft[i - 1]) * maxRight[i]);

    return ans;
  }

 private:
  static constexpr int kBase = 26;
  static constexpr int kHash = 1'000'000'007;

  static constexpr int val(char c) {
    return c - 'a';
  }

  // Returns true if s[l..r) is a palindrome.
  bool isPalindrome(int l, int r, const vector<long>& hashL,
                    const vector<long>& hashR, const vector<long>& pows) {
    return getLeftRollingHash(l, r, hashL, pows) ==
           getRightRollingHash(l, r, hashR, pows);
  }

  // Returns the left rolling hash of s[l..r).
  long getLeftRollingHash(int l, int r, const vector<long>& hashL,
                          const vector<long>& pows) {
    const long h = (hashL[r] - hashL[l] * pows[r - l]) % kHash;
    return h < 0 ? h + kHash : h;
  }

  // Returns the right rolling hash of s[l..r).
  long getRightRollingHash(int l, int r, const vector<long>& hashR,
                           const vector<long>& pows) {
    const long h = (hashR[l] - hashR[r] * pows[r - l]) % kHash;
    return h < 0 ? h + kHash : h;
  }
};
