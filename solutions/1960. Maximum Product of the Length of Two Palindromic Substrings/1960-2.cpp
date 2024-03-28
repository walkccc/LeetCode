class Solution {
 public:
  long long maxProduct(string s) {
    const int n = s.length();
    long long ans = 1;
    vector<long> pow(n + 1);        // pow[i] := kBase^i
    vector<long> hashFromL(n + 1);  // hashFromL[i] = the hash of s[0..i)
    vector<long> hashFromR(n + 1);  // hashFromR[i] = the hash of s[i..n)
    vector<int> l(n);  // l[i] := the maximum length of palindromes in s[0..i)
    vector<int> r(n);  // r[i] := the maximum length of palindromes in s[i..n)

    pow[0] = 1;
    for (int i = 1; i <= n; ++i)
      pow[i] = pow[i - 1] * kBase % kMod;

    for (int i = 1; i <= n; ++i)
      hashFromL[i] = (hashFromL[i - 1] * kBase + val(s[i - 1])) % kMod;

    for (int i = n - 1; i >= 0; --i)
      hashFromR[i] = (hashFromR[i + 1] * kBase + val(s[i])) % kMod;

    int max = 1;  // the maximum length of palindromes so far
    for (int i = 0; i < n; i++) {
      if (i - max - 1 >= 0 &&
          isPalindrome(i - max - 1, i + 1, hashFromL, hashFromR, pow))
        max += 2;
      l[i] = max;
    }

    // Fill in r.
    max = 1;
    for (int i = n - 1; i >= 0; i--) {
      if (i + max + 2 <= n &&
          isPalindrome(i, i + max + 2, hashFromL, hashFromR, pow))
        max += 2;
      r[i] = max;
    }

    for (int i = 0; i + 1 < n; ++i)
      ans = std::max(ans, (long long)l[i] * r[i + 1]);

    return ans;
  }

 private:
  static constexpr int kBase = 26;
  static constexpr int kMod = 1'000'000'007;

  // Returns true if s[l..r) is a palindrome.
  bool isPalindrome(int l, int r, const vector<long>& hashFromL,
                    const vector<long>& hashFromR, const vector<long>& pow) {
    return leftHash(l, r, hashFromL, pow) == rightHash(l, r, hashFromR, pow);
  }

  // Returns the hash of s[l..r) from the left.
  long leftHash(int l, int r, const vector<long>& hashFromL,
                const vector<long>& pow) {
    const long hash = (hashFromL[r] - hashFromL[l] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  // Returns the hash of s[l..r) from the right.
  long rightHash(int l, int r, const vector<long>& hashFromR,
                 const vector<long>& pow) {
    const long hash = (hashFromR[l] - hashFromR[r] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  constexpr int val(char c) {
    return c - 'a';
  }
};
