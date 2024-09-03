class Solution {
 public:
  string modifyString(string s) {
    string ans;

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '?')
        ans += nextAvailable(ans, s, i);
      else
        ans += s[i];

    return ans;
  }

 private:
  char nextAvailable(const string& ans, const string& s, int i) {
    char c = 'a';
    while ((i > 0 && ans[i - 1] == c) ||  //
           (i + 1 < s.size() && c == s[i + 1]))
      ++c;
    return c;
  }
};
