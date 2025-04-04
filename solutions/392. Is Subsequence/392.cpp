class Solution {
 public:
  bool isSubsequence(string s, string t) {
    if (s.empty())
      return true;

    int i = 0;
    for (const char c : t)
      if (s[i] == c && ++i == s.length())
        return true;

    return false;
  }
};
