class Solution {
 public:
  int countGoodSubstrings(string s) {
    int ans = 0;

    for (int i = 0; i < (int)s.length() - 2; ++i) {
      const char a = s[i];
      const char b = s[i + 1];
      const char c = s[i + 2];
      if (a == b || a == c || b == c)
        continue;
      ++ans;
    }

    return ans;
  }
};
