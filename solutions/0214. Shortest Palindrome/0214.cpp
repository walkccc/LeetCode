class Solution {
 public:
  string shortestPalindrome(string s) {
    string t = s;
    reverse(begin(t), end(t));

    const string_view sv_s(s);
    const string_view sv_t(t);

    for (int i = 0; i < s.length(); ++i)
      if (sv_s.substr(0, s.length() - i) == sv_t.substr(i))
        return t.substr(0, i) + s;

    return t + s;
  }
};
