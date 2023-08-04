class Solution {
 public:
  string replaceDigits(string s) {
    for (int i = 0; i < s.length(); ++i)
      s[i] += s[i - 1] - '0';
    return s;
  }
};
