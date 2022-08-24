class Solution {
 public:
  bool isOneEditDistance(string s, string t) {
    const int m = s.length();
    const int n = t.length();
    if (m > n)  // make sure len(s) <= len(t)
      return isOneEditDistance(t, s);

    for (int i = 0; i < m; ++i)
      if (s[i] != t[i]) {
        if (m == n)
          return s.substr(i + 1) == t.substr(i + 1);  // replace s[i] with t[i]
        return s.substr(i) == t.substr(i + 1);        // delete t[i]
      }

    return m + 1 == n;  // delete t[-1]
  }
};
