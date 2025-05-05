class Solution {
 public:
  int countSubstrings(string s, string t) {
    int ans = 0;

    for (int i = 0; i < s.length(); ++i)
      ans += count(s, t, i, 0);

    for (int j = 1; j < t.length(); ++j)
      ans += count(s, t, 0, j);

    return ans;
  }

 private:
  // Returns the number of substrings of s[i..n) and t[j..n) that differ by one
  // letter.
  int count(const string& s, const string& t, int i, int j) {
    int res = 0;
    // the number of substrings starting at s[i] and t[j] ending in the current
    // index with zero different letter
    int dp0 = 0;
    // the number of substrings starting at s[i] and t[j] ending in the current
    // index with one different letter
    int dp1 = 0;

    for (; i < s.length() && j < t.length(); ++i, ++j) {
      if (s[i] == t[j]) {
        ++dp0;
      } else {
        dp1 = dp0 + 1;
        dp0 = 0;
      }
      res += dp1;
    }

    return res;
  }
};
