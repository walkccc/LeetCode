class Solution {
 public:
  long long maxProduct(string s) {
    const int n = s.length();
    long long ans = 1;
    // l[i] := max length of palindromes in s[0..i)
    vector<int> l = manacher(s, n);
    // r[i] := max length of palindromes in s[i..n)
    vector<int> r = manacher(string(rbegin(s), rend(s)), n);
    reverse(begin(r), end(r));

    for (int i = 0; i + 1 < n; ++i)
      ans = max(ans, (long long)l[i] * r[i + 1]);

    return ans;
  }

 private:
  vector<int> manacher(const string& s, int n) {
    vector<int> maxExtends(n);
    vector<int> l2r(n, 1);
    int center = 0;

    for (int i = 0; i < n; ++i) {
      const int r = center + maxExtends[center] - 1;
      const int mirrorIndex = center - (i - center);
      int extend = i > r ? 1 : min(maxExtends[mirrorIndex], r - i + 1);
      while (i - extend >= 0 && i + extend < n &&
             s[i - extend] == s[i + extend]) {
        l2r[i + extend] = 2 * extend + 1;
        ++extend;
      }
      maxExtends[i] = extend;
      if (i + maxExtends[i] >= r)
        center = i;
    }

    for (int i = 1; i < n; ++i)
      l2r[i] = max(l2r[i], l2r[i - 1]);

    return l2r;
  }
};
