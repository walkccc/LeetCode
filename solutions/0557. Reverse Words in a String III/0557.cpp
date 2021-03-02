class Solution {
 public:
  string reverseWords(string s) {
    int i = 0;
    int j = 0;

    while (i < s.length()) {
      while (i < j || i < s.length() && s[i] == ' ')
        ++i;
      while (j < i || j < s.length() && s[j] != ' ')
        ++j;
      reverse(begin(s) + i, begin(s) + j);
    }

    return s;
  }
};
