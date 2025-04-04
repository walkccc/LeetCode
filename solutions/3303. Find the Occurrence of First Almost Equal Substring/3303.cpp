class Solution {
 public:
  int minStartingIndex(string s, string pattern) {
    const vector<int> z1 = zFunction(pattern + s);
    const vector<int> z2 = zFunction(reversed(pattern) + reversed(s));

    // Match s[i..i + len(pattern) - 1] with `pattern` from both the prefix and
    // the suffix.
    for (int i = 0; i <= s.length() - pattern.length(); ++i)
      if (z1[pattern.length() + i] + z2[s.length() - i] >= pattern.length() - 1)
        return i;

    return -1;
  }

 private:
  // Returns the z array, where z[i] is the length of the longest prefix of
  // s[i..n) which is also a prefix of s.
  //
  // https://cp-algorithms.com/string/z-function.html#implementation
  vector<int> zFunction(const string& s) {
    const int n = s.length();
    vector<int> z(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
      if (i < r)
        z[i] = min(r - i, z[i - l]);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        ++z[i];
      if (i + z[i] > r) {
        l = i;
        r = i + z[i];
      }
    }
    return z;
  }

  string reversed(const string& s) {
    return {s.rbegin(), s.rend()};
  }
};
