class Solution {
 public:
  long long maxProduct(string s) {
    const int n = s.length();
    long long ans = 1;
    vector<long> pow(n + 1);        // pow[i] := kBase^i
    vector<long> hashFromL(n + 1);  // hashFromL[i] = hash value of s[0..i)
    vector<long> hashFromR(n + 1);  // hashFromR[i] = hash value of s[i..n)
    vector<int> l(n);  // l[i] := max length of palindromes in s[0..i)
    vector<int> r(n);  // r[i] := max length of palindromes in s[i..n)

    pow[0] = 1;
    for (int i = 1; i <= n; ++i)
      pow[i] = pow[i - 1] * kBase % kMod;

    for (int i = 1; i <= n; ++i)
      hashFromL[i] = (hashFromL[i - 1] * kBase + val(s[i - 1])) % kMod;

    for (int i = n - 1; i >= 0; --i)
      hashFromR[i] = (hashFromR[i + 1] * kBase + val(s[i])) % kMod;

    int max = 1;  // max length of palindromes so far
    for (int i = 0; i < n; i++) {
      if (i - max - 1 >= 0 &&
          isPalindrome(i - max - 1, i + 1, hashFromL, hashFromR, pow))
        max += 2;
      l[i] = max;
    }

    // fill in r
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
  constexpr static int kBase = 26;
  constexpr static int kMod = 1'000'000'007;

  // true if s[l..r) is palindrome
  bool isPalindrome(int l, int r, const vector<long>& hashFromL,
                    const vector<long>& hashFromR, const vector<long>& pow) {
    return leftHash(l, r, hashFromL, pow) == rightHash(l, r, hashFromR, pow);
  }

  long leftHash(int l, int r, const vector<long>& hashFromL,
                const vector<long>& pow) {
    const long hash = (hashFromL[r] - hashFromL[l] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  long rightHash(int l, int r, const vector<long>& hashFromR,
                 const vector<long>& pow) {
    const long hash = (hashFromR[l] - hashFromR[r] * pow[r - l]) % kMod;
    return hash < 0 ? hash + kMod : hash;
  }

  int val(char c) {
    return c - 'a' + 1;
  }
};
