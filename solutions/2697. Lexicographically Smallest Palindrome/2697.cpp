class Solution {
 public:
  string makeSmallestPalindrome(string s) {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
      const int minChar = min(s[i], s[j]);
      s[i] = minChar;
      s[j] = minChar;
    }
    return s;
  }
};
